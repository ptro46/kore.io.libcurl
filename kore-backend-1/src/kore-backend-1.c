#include <kore/kore.h>
#include <kore/http.h>
#include <kore/curl.h>

#include "s_curl.h"

int    call_get_req_1(struct http_request *);
int    call_get_req_2(struct http_request *);
int    call_get_req_3(struct http_request *);
int    call_get_req_4(struct http_request *);
int    call_get_req_1_2(struct http_request *);
int    call_get_req_1_2_3_4(struct http_request *);

int    call_get_req_1(struct http_request *req) {
    struct kore_buf          buf;
    struct kore_buf          errors;
    struct kore_curl*        client;

    printf("kore-backend-1 :: begin :: call get /req_1\n");
    req->status = HTTP_STATUS_INTERNAL_ERROR;
    kore_buf_init(&buf, 512);
    kore_buf_init(&errors, 512);
	client = http_state_create(req, sizeof(*client));
    if ( client != NULL ) {
        printf("kore-backend-1 call GET https://localhost:8888/api\n");
        if ( curl_execute(client,
                          &buf,
                          &errors,
                          "https://localhost:8888/api",
                          HTTP_METHOD_GET,
                          NULL,
                          0) ) {
            req->status = HTTP_STATUS_OK;
        } else {
            kore_buf_append(&buf, errors.data, errors.offset);           
        }
        kore_curl_cleanup(client);
    } else {
        kore_buf_appendf(&buf, "Error : can not create client");
    }
    
    printf("kore-backend-1 :: end :: call get /req_1\n");
    http_response(req, req->status, buf.data, buf.offset);
    kore_buf_cleanup(&errors);
    kore_buf_cleanup(&buf);
    return KORE_RESULT_OK;
}

/* {"idt":1,"msg":"string message"} */
int    call_get_req_2(struct http_request *req) {
    struct kore_buf          buf;
    struct kore_buf          errors;
    struct kore_buf          payload;
    struct kore_curl*        client;

    printf("kore-backend-1 :: begin :: call get /req_2\n");
    req->status = HTTP_STATUS_INTERNAL_ERROR;
    kore_buf_init(&payload, 512);
    kore_buf_init(&buf, 512);
    kore_buf_init(&errors, 512);
	client = http_state_create(req, sizeof(*client));
    if ( client != NULL ) {
        kore_buf_appendf(&payload, "{\"idt\":1,\"msg\":\"string message POST\"}");
        printf("kore-backend-1 call POST https://localhost:8888/api\n");
        if ( curl_execute(client,
                          &buf,
                          &errors,
                          "https://localhost:8888/api",
                          HTTP_METHOD_POST,
                          &payload,
                          0) ) {
            req->status = HTTP_STATUS_OK;
        } else {
            kore_buf_append(&buf, errors.data, errors.offset);           
        }
        kore_curl_cleanup(client);
    } else {
        kore_buf_appendf(&buf, "Error : can not create client");
    }
    
    printf("kore-backend-1 :: end :: call get /req_2\n");
    http_response(req, req->status, buf.data, buf.offset);
    kore_buf_cleanup(&errors);
    kore_buf_cleanup(&buf);
    kore_buf_cleanup(&payload);
    return KORE_RESULT_OK;
}

int    call_get_req_3(struct http_request *req) {
    struct kore_buf          buf;
    struct kore_buf          errors;
    struct kore_buf          payload;
    struct kore_curl*        client;

    printf("kore-backend-1 :: begin :: call get /req_3\n");
    req->status = HTTP_STATUS_INTERNAL_ERROR;
    kore_buf_init(&payload, 512);
    kore_buf_init(&buf, 512);
    kore_buf_init(&errors, 512);
	client = http_state_create(req, sizeof(*client));
    if ( client != NULL ) {
        kore_buf_appendf(&payload, "{\"idt\":2,\"msg\":\"string message PUT\"}");
        printf("kore-backend-1 call PUT https://localhost:8888/api\n");
        if ( curl_execute(client,
                          &buf,
                          &errors,
                          "https://localhost:8888/api",
                          HTTP_METHOD_PUT,
                          &payload,
                          0) ) {
            req->status = HTTP_STATUS_OK;
        } else {
            kore_buf_append(&buf, errors.data, errors.offset);           
        }
        kore_curl_cleanup(client);
    } else {
        kore_buf_appendf(&buf, "Error : can not create client");
    }
    
    printf("kore-backend-1 :: end :: call get /req_3\n");
    http_response(req, req->status, buf.data, buf.offset);
    kore_buf_cleanup(&errors);
    kore_buf_cleanup(&buf);
    kore_buf_cleanup(&payload);
    return KORE_RESULT_OK;
}

int    call_get_req_4(struct http_request *req) {
    struct kore_buf          buf;
    struct kore_buf          errors;
    struct kore_curl*        client;

    printf("kore-backend-1 :: begin :: call get /req_4\n");
    req->status = HTTP_STATUS_INTERNAL_ERROR;
    kore_buf_init(&buf, 512);
    kore_buf_init(&errors, 512);
	client = http_state_create(req, sizeof(*client));
    if ( client != NULL ) {
        printf("kore-backend-1 call DELETE https://localhost:8888/api\n");
        if ( curl_execute(client,
                          &buf,
                          &errors,
                          "https://localhost:8888/api",
                          HTTP_METHOD_DELETE,
                          NULL,
                          0) ) {
            req->status = HTTP_STATUS_OK;
        } else {
            kore_buf_append(&buf, errors.data, errors.offset);           
        }
        kore_curl_cleanup(client);
    } else {
        kore_buf_appendf(&buf, "Error : can not create client");
    }
    
    printf("kore-backend-1 :: end :: call get /req_4\n");
    http_response(req, req->status, buf.data, buf.offset);
    kore_buf_cleanup(&errors);
    kore_buf_cleanup(&buf);
    return KORE_RESULT_OK;
}

int    call_get_req_1_2(struct http_request *req) {    
    struct kore_buf          payload;
    struct kore_buf          buf;
    struct kore_buf          buf_result_get;
    struct kore_buf          buf_result_post;
    struct kore_buf          errors;
    struct kore_curl*        client;

    printf("kore-backend-1 :: begin :: call get /req_1_2\n");
    req->status = HTTP_STATUS_INTERNAL_ERROR;
    kore_buf_init(&payload, 512);
    kore_buf_init(&buf, 512);
    kore_buf_init(&buf_result_get, 512);
    kore_buf_init(&buf_result_post, 512);
    kore_buf_init(&errors, 512);
	client = http_state_create(req, sizeof(*client));
    if ( client != NULL ) {
        printf("kore-backend-1 call GET https://localhost:8888/api\n");
        if ( curl_execute(client,
                          &buf_result_get,
                          &errors,
                          "https://localhost:8888/api",
                          HTTP_METHOD_GET,
                          NULL,
                          0) ) {

            kore_buf_appendf(&payload, "{\"idt\":1,\"msg\":\"string message POST\"}");
            printf("kore-backend-1 call POST https://localhost:8888/api\n");
            if ( curl_execute(client,
                              &buf_result_post,
                              &errors,
                              "https://localhost:8888/api",
                              HTTP_METHOD_POST,
                              &payload,
                              0) ) {
                req->status = HTTP_STATUS_OK;

                kore_buf_appendf(&buf,
                                 "\"payload_get\":%s,\"payload_post\":%s",
                                 kore_buf_stringify(&buf_result_get, NULL),
                                 kore_buf_stringify(&buf_result_post, NULL));
                
            } else {
                kore_buf_append(&buf, errors.data, errors.offset);           
            }
        } else {
            kore_buf_append(&buf, errors.data, errors.offset);           
        }
        kore_curl_cleanup(client);
    } else {
        kore_buf_appendf(&buf, "Error : can not create client");
    }
    
    printf("kore-backend-1 :: end :: call get /req_1_2\n");
    http_response(req, req->status, buf.data, buf.offset);
    kore_buf_cleanup(&errors);
    kore_buf_cleanup(&buf_result_get);
    kore_buf_cleanup(&buf_result_post);
    kore_buf_cleanup(&buf);
    kore_buf_cleanup(&payload);
    return KORE_RESULT_OK;
}

int    call_get_req_1_2_3_4(struct http_request *req) {    
    struct kore_buf          payload;
    struct kore_buf          buf;
    struct kore_buf          buf_result_get;
    const char*              psz_header_response_get = "";

    struct kore_buf          buf_result_post;
    const char*              psz_header_response_post_1 = "";
    const char*              psz_header_response_post_2 = "";

    struct kore_buf          buf_result_put;
    const char*              psz_header_response_put_1 = "";
    const char*              psz_header_response_put_2 = "";
    
    struct kore_buf          buf_result_delete;
    const char*              psz_header_response_delete = "";
    
    struct kore_buf          errors;
    struct kore_curl*        client;

    printf("kore-backend-1 :: begin :: call get /req_1_2\n");
    req->status = HTTP_STATUS_INTERNAL_ERROR;
    kore_buf_init(&payload, 512);
    kore_buf_init(&buf, 512);
    kore_buf_init(&buf_result_get, 512);
    kore_buf_init(&buf_result_post, 512);
    kore_buf_init(&buf_result_put, 512);
    kore_buf_init(&buf_result_delete, 512);
    kore_buf_init(&errors, 512);
	client = http_state_create(req, sizeof(*client));
    if ( client != NULL ) {
        printf("kore-backend-1 call GET https://localhost:8888/api\n");
        if ( curl_execute(client,
                          &buf_result_get,
                          &errors,
                          "https://localhost:8888/api",
                          HTTP_METHOD_GET,
                          NULL,
                          1,
                          "key_header_get","value_header_get") ) {
            if ( ! kore_curl_http_get_header(client, "x-custom-header-get", &psz_header_response_get) ) {
                psz_header_response_get = "" ;
            }
            kore_buf_reset(&payload);
            kore_buf_appendf(&payload, "{\"idt\":1,\"msg\":\"string message POST\"}");
            printf("kore-backend-1 call POST https://localhost:8888/api\n");
            if ( curl_execute(client,
                              &buf_result_post,
                              &errors,
                              "https://localhost:8888/api",
                              HTTP_METHOD_POST,
                              &payload,
                              2,
                              "key_header_post_1","value_header_post_1",
                              "key_header_post_2","value_header_post_2") ) {
                if ( ! kore_curl_http_get_header(client, "x-custom-header-post-1", &psz_header_response_post_1) ) {
                    psz_header_response_post_1 = "" ;
                }
                if ( ! kore_curl_http_get_header(client, "x-custom-header-post-2", &psz_header_response_post_2) ) {
                    psz_header_response_post_2 = "" ;
                }
                kore_buf_reset(&payload);
                kore_buf_appendf(&payload, "{\"idt\":2,\"msg\":\"string message PUT\"}");
                printf("kore-backend-1 call PUT https://localhost:8888/api\n");
                if ( curl_execute(client,
                                  &buf_result_put,
                                  &errors,
                                  "https://localhost:8888/api",
                                  HTTP_METHOD_PUT,
                                  &payload,
                                  2,
                                  "key_header_put_1","value_header_put_1",
                                  "key_header_put_2","value_header_put_2") ) {
                    if ( ! kore_curl_http_get_header(client, "x-custom-header-put-1", &psz_header_response_put_1) ) {
                        psz_header_response_put_1 = "" ;
                    }
                    if ( ! kore_curl_http_get_header(client, "x-custom-header-put-2", &psz_header_response_put_2) ) {
                        psz_header_response_put_2 = "" ;
                    }
                    printf("kore-backend-1 call DELETE https://localhost:8888/api\n");
                    if ( curl_execute(client,
                                      &buf_result_delete,
                                      &errors,
                                      "https://localhost:8888/api",
                                      HTTP_METHOD_DELETE,
                                      NULL,
                                      1,
                                      "key_header_delete","value_header_delete") ) {
                        if ( ! kore_curl_http_get_header(client, "x-custom-header-delete", &psz_header_response_delete) ) {
                            psz_header_response_delete = "" ;
                        }
                        req->status = HTTP_STATUS_OK;

                        kore_buf_appendf(&buf,
                                         "{\"payload_get\":%s,\"payload_post\":%s,\"payload_put\":%s,\"payload_delete\":%s",
                                         kore_buf_stringify(&buf_result_get, NULL),
                                         kore_buf_stringify(&buf_result_post, NULL),
                                         kore_buf_stringify(&buf_result_put, NULL),
                                         kore_buf_stringify(&buf_result_delete, NULL));
                        kore_buf_appendf(&buf,
                                         ",\"x-custom-header-get\":\"%s\"",
                                         psz_header_response_get);
                        kore_buf_appendf(&buf,
                                         ",\"x-custom-header-post-1\":\"%s\",\"x-custom-header-post-2\":\"%s\"",
                                         psz_header_response_post_1,
                                         psz_header_response_post_2);
                        kore_buf_appendf(&buf,
                                         ",\"x-custom-header-put-1\":\"%s\",\"x-custom-header-put-2\":\"%s\"",
                                         psz_header_response_put_1,
                                         psz_header_response_put_2);
                        kore_buf_appendf(&buf,
                                         ",\"x-custom-header-delete\":\"%s\"}",
                                         psz_header_response_delete);
                    } else {
                        kore_buf_append(&buf, errors.data, errors.offset);           
                    }
                } else {
                    kore_buf_append(&buf, errors.data, errors.offset);           
                }                
            } else {
                kore_buf_append(&buf, errors.data, errors.offset);           
            }
        } else {
            kore_buf_append(&buf, errors.data, errors.offset);           
        }
        kore_curl_cleanup(client);
    } else {
        kore_buf_appendf(&buf, "Error : can not create client");
    }
    
    printf("kore-backend-1 :: end :: call get /req_1_2\n");
    http_response(req, req->status, buf.data, buf.offset);
    kore_buf_cleanup(&errors);
    kore_buf_cleanup(&buf_result_get);
    kore_buf_cleanup(&buf_result_post);
    kore_buf_cleanup(&buf_result_put);
    kore_buf_cleanup(&buf_result_delete);
    kore_buf_cleanup(&buf);
    kore_buf_cleanup(&payload);
    return KORE_RESULT_OK;
}
