/*
 * New cryptographic library (ncrypt.dll)
 *
 * Copyright 2016 Alex Henrie
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include <stdarg.h>
#include <stdlib.h>

#include "windef.h"
#include "winbase.h"
#include "ncrypt.h"
#include "bcrypt.h"
#include "ncrypt_internal.h"
#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(ncrypt);

SECURITY_STATUS WINAPI NCryptCreatePersistedKey(NCRYPT_PROV_HANDLE provider, NCRYPT_KEY_HANDLE *key,
                                                const WCHAR *algid, const WCHAR *name, DWORD keyspec, DWORD flags)
{
    FIXME("(%#Ix, %p, %s, %s, %#lx, %#lx): stub\n", provider, key, wine_dbgstr_w(algid),
          wine_dbgstr_w(name), keyspec, flags);
    return NTE_NOT_SUPPORTED;
}

SECURITY_STATUS WINAPI NCryptDecrypt(NCRYPT_KEY_HANDLE key, BYTE *input, DWORD insize, void *padding,
                                     BYTE *output, DWORD outsize, DWORD *result, DWORD flags)
{
    FIXME("(%#Ix, %p, %lu, %p, %p, %lu, %p, %#lx): stub\n", key, input, insize, padding,
          output, outsize, result, flags);
    return NTE_NOT_SUPPORTED;
}

SECURITY_STATUS WINAPI NCryptDeleteKey(NCRYPT_KEY_HANDLE key, DWORD flags)
{
    FIXME("(%#Ix, %#lx): stub\n", key, flags);
    return NTE_NOT_SUPPORTED;
}

SECURITY_STATUS WINAPI NCryptEncrypt(NCRYPT_KEY_HANDLE key, BYTE *input, DWORD insize, void *padding,
                                     BYTE *output, DWORD outsize, DWORD *result, DWORD flags)
{
    FIXME("(%#Ix, %p, %lu, %p, %p, %lu, %p, %#lx): stub\n", key, input, insize, padding,
          output, outsize, result, flags);
    return NTE_NOT_SUPPORTED;
}

SECURITY_STATUS WINAPI NCryptEnumAlgorithms(NCRYPT_PROV_HANDLE provider, DWORD alg_ops,
                                            DWORD *alg_count, NCryptAlgorithmName **alg_list, DWORD flags)
{
    FIXME("(%#Ix, %#lx, %p, %p, %#lx): stub\n", provider, alg_ops, alg_count, alg_list, flags);
    return NTE_NOT_SUPPORTED;
}

SECURITY_STATUS WINAPI NCryptEnumKeys(NCRYPT_PROV_HANDLE provider, const WCHAR *scope,
                                      NCryptKeyName **key_name, PVOID *enum_state, DWORD flags)
{
    FIXME("(%#Ix, %p, %p, %p, %#lx): stub\n", provider, scope, key_name, enum_state, flags);
    return NTE_NOT_SUPPORTED;
}

SECURITY_STATUS WINAPI NCryptFinalizeKey(NCRYPT_KEY_HANDLE key, DWORD flags)
{
    FIXME("(%#Ix, %#lx): stub\n", key, flags);
    return NTE_NOT_SUPPORTED;
}

SECURITY_STATUS WINAPI NCryptFreeBuffer(PVOID buf)
{
    FIXME("(%p): stub\n", buf);
    return NTE_NOT_SUPPORTED;
}

static SECURITY_STATUS free_key_object(struct key *key)
{
    switch (key->alg)
    {
    case RSA:
    {
        free(key->rsa.modulus);
        free(key->rsa.public_exp);
        free(key->rsa.prime1);
        free(key->rsa.prime2);
        break;
    }
    default:
        WARN("invalid key %p\n", key);
        return NTE_INVALID_HANDLE;
    }
    return ERROR_SUCCESS;
}

SECURITY_STATUS WINAPI NCryptFreeObject(NCRYPT_HANDLE handle)
{
    struct object *object = (struct object *)handle;
    SECURITY_STATUS ret = ERROR_SUCCESS;
    unsigned int i;

    TRACE("(%#Ix)\n", handle);

    if (!object)
    {
        WARN("invalid handle %#Ix\n", handle);
        return NTE_INVALID_HANDLE;
    }

    switch (object->type)
    {
    case KEY:
    {
        if ((ret = free_key_object(&object->key))) return ret;
        break;
    }
    case STORAGE_PROVIDER:
        break;

    default:
        WARN("invalid handle %#Ix\n", handle);
        return NTE_INVALID_HANDLE;
    }

    for (i = 0; i < object->num_properties; i++)
    {
        free(object->properties[i].key);
        free(object->properties[i].value);
    }
    free(object->properties);
    free(object);
    return ret;
}

static const struct object_property *get_object_property(struct object *object, const WCHAR *name)
{
    unsigned int i;
    for (i = 0; i < object->num_properties; i++)
    {
        const struct object_property *property = &object->properties[i];
        if (!lstrcmpW(property->key, name)) return property;
    }
    return NULL;
}

SECURITY_STATUS WINAPI NCryptGetProperty(NCRYPT_HANDLE handle, const WCHAR *name, BYTE *output,
                                         DWORD outsize, DWORD *result, DWORD flags)
{
    struct object *object = (struct object *)handle;
    const struct object_property *property;

    TRACE("(%#Ix, %s, %p, %lu, %p, %#lx)\n", handle, wine_dbgstr_w(name), output, outsize, result, flags);
    if (flags) FIXME("flags %#lx not supported\n", flags);

    if (!(property = get_object_property(object, name))) return NTE_INVALID_PARAMETER;
    *result = property->value_size;
    if (!output) return ERROR_SUCCESS;
    if (outsize < property->value_size) return NTE_BUFFER_TOO_SMALL;

    memcpy(output, property->value, property->value_size);
    return ERROR_SUCCESS;
}

static struct object *allocate_object(enum object_type type)
{
    struct object *ret;
    if (!(ret = calloc(1, sizeof(*ret)))) return NULL;
    ret->type = type;
    return ret;
}

static SECURITY_STATUS set_object_property(struct object *object, const WCHAR *name, BYTE *value, DWORD value_size)
{
    struct object_property *property;

    FIXME("check duplicates\n");
    if (!object->num_properties)
    {
        if (!(object->properties = malloc(sizeof(*property))))
        {
            ERR("Error allocating memory.");
            return NTE_NO_MEMORY;
        }
        property = &object->properties[object->num_properties++];
    }
    else
    {
        struct object_property *tmp;
        if (!(tmp = realloc(object->properties, sizeof(*property) * (object->num_properties + 1))))
        {
            ERR("Error allocating memory.");
            return NTE_NO_MEMORY;
        }
        object->properties = tmp;
        property = &object->properties[object->num_properties++];
    }

    memset(property, 0, sizeof(*property));
    if (!(property->key = malloc((lstrlenW(name) + 1) * sizeof(WCHAR))))
    {
        ERR("Error allocating memory.");
        return NTE_NO_MEMORY;
    }

    lstrcpyW(property->key, name);
    property->value_size = value_size;
    if (!(property->value = malloc(value_size)))
    {
        ERR("Error allocating memory.");
        free(property->key);
        property->key = NULL;
        return NTE_NO_MEMORY;
    }

    memcpy(property->value, value, value_size);
    return ERROR_SUCCESS;
}

SECURITY_STATUS WINAPI NCryptImportKey(NCRYPT_PROV_HANDLE provider, NCRYPT_KEY_HANDLE decrypt_key,
                                       const WCHAR *type, NCryptBufferDesc *params, NCRYPT_KEY_HANDLE *handle,
                                       BYTE *data, DWORD datasize, DWORD flags)
{
    BCRYPT_KEY_BLOB *header = (BCRYPT_KEY_BLOB *)data;

    TRACE("(%#Ix, %#Ix, %s, %p, %p, %p, %lu, %#lx): stub\n", provider, decrypt_key, wine_dbgstr_w(type),
          params, handle, data, datasize, flags);

    if (decrypt_key)
    {
        FIXME("Key blob decryption not implemented\n");
        return NTE_NOT_SUPPORTED;
    }
    if (params)
    {
        FIXME("Parameter information not implemented\n");
        return NTE_NOT_SUPPORTED;
    }
    if (flags == NCRYPT_SILENT_FLAG)
    {
        FIXME("Silent flag not implemented\n");
    }
    else if (flags)
    {
        ERR("Invalid flags %#lx\n", flags);
        return NTE_BAD_FLAGS;
    }

    switch (header->Magic)
    {
    case BCRYPT_RSAPUBLIC_MAGIC:
    {
        DWORD expected_size;
        struct object *object;
        struct key *key;
        BYTE *public_exp, *modulus;
        BCRYPT_RSAKEY_BLOB *rsaheader = (BCRYPT_RSAKEY_BLOB *)data;

        if (datasize < sizeof(*rsaheader))
        {
            ERR("Invalid buffer size.\n");
            return NTE_BAD_DATA;
        }

        expected_size = sizeof(*rsaheader) + rsaheader->cbPublicExp + rsaheader->cbModulus;
        if (datasize != expected_size)
        {
            ERR("Invalid buffer size.\n");
            return NTE_BAD_DATA;
        }

        if (!(object = allocate_object(KEY)))
        {
            ERR("Error allocating memory.\n");
            return NTE_NO_MEMORY;
        }

        key = &object->key;
        key->alg = RSA;
        key->rsa.bit_length = rsaheader->BitLength;
        key->rsa.public_exp_size = rsaheader->cbPublicExp;
        key->rsa.modulus_size = rsaheader->cbModulus;
        if (!(key->rsa.public_exp = malloc(rsaheader->cbPublicExp)))
        {
            ERR("Error allocating memory.\n");
            free(object);
            return NTE_NO_MEMORY;
        }
        if (!(key->rsa.modulus = malloc(rsaheader->cbModulus)))
        {
            ERR("Error allocating memory.\n");
            free(key->rsa.public_exp);
            free(object);
            return NTE_NO_MEMORY;
        }

        public_exp = &data[sizeof(*rsaheader)]; /* The public exp is after the header. */
        modulus = &public_exp[rsaheader->cbPublicExp]; /* The modulus is after the public exponent. */
        memcpy(key->rsa.public_exp, public_exp, rsaheader->cbPublicExp);
        memcpy(key->rsa.modulus, modulus, rsaheader->cbModulus);

        set_object_property(object, NCRYPT_ALGORITHM_GROUP_PROPERTY, (BYTE *)L"RSA", sizeof(L"RSA"));
        set_object_property(object, NCRYPT_LENGTH_PROPERTY, (BYTE *)&key->rsa.bit_length, sizeof(key->rsa.bit_length));
        set_object_property(object, NCRYPT_PROVIDER_HANDLE_PROPERTY, (BYTE *)&provider, sizeof(provider));
        *handle = (NCRYPT_KEY_HANDLE)object;
        break;
    }
    default:
        FIXME("Unhandled key magic %#lx.\n", header->Magic);
        return NTE_INVALID_PARAMETER;
    }

    return ERROR_SUCCESS;
}

SECURITY_STATUS WINAPI NCryptIsAlgSupported(NCRYPT_PROV_HANDLE provider, const WCHAR *algid, DWORD flags)
{
    FIXME("(%#Ix, %s, %#lx): stub\n", provider, wine_dbgstr_w(algid), flags);
    return NTE_NOT_SUPPORTED;
}

BOOL WINAPI NCryptIsKeyHandle(NCRYPT_KEY_HANDLE hKey)
{
    FIXME("(%#Ix): stub\n", hKey);
    return FALSE;
}

SECURITY_STATUS WINAPI NCryptOpenKey(NCRYPT_PROV_HANDLE provider, NCRYPT_KEY_HANDLE *key,
                                     const WCHAR *name, DWORD keyspec, DWORD flags)
{
    FIXME("(%#Ix, %p, %s, %#lx, %#lx): stub\n", provider, key, wine_dbgstr_w(name), keyspec, flags);
    return NTE_NOT_SUPPORTED;
}

SECURITY_STATUS WINAPI NCryptOpenStorageProvider(NCRYPT_PROV_HANDLE *provider, const WCHAR *name, DWORD flags)
{
    struct object *object;

    FIXME("(%p, %s, %#lx): stub\n", provider, wine_dbgstr_w(name), flags);

    if (!(object = allocate_object(STORAGE_PROVIDER)))
    {
        ERR("Error allocating memory.\n");
        return NTE_NO_MEMORY;
    }
    *provider = (NCRYPT_PROV_HANDLE)object;
    return ERROR_SUCCESS;
}

SECURITY_STATUS WINAPI NCryptSetProperty(NCRYPT_HANDLE handle, const WCHAR *name, BYTE *input, DWORD insize, DWORD flags)
{
    struct object *object = (struct object *)handle;

    TRACE("(%#Ix, %s, %p, %lu, %#lx)\n", handle, wine_dbgstr_w(name), input, insize, flags);
    if (flags) FIXME("flags %#lx not supported\n", flags);

    return set_object_property(object, name, input, insize);
}

SECURITY_STATUS WINAPI NCryptVerifySignature(NCRYPT_KEY_HANDLE handle, void *padding, BYTE *hash, DWORD hash_size,
                                             BYTE *signature, DWORD signature_size, DWORD flags)
{
    FIXME("(%#Ix, %p, %p, %lu, %p, %lu, %#lx): stub\n", handle, padding, hash, hash_size, signature,
          signature_size, flags);
    return ERROR_SUCCESS;
}
