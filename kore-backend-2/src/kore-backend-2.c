#include <kore/kore.h>
#include <kore/http.h>
#include <unistd.h>

int
api_get(struct http_request *);

int
api_post(struct http_request *);

int
api_put(struct http_request *);

int
api_delete(struct http_request *);

void
create_foo_json(struct kore_json_item** item,
                int i,
                double d,
                const char* psz,
                struct kore_json* p_json_payload);

void
create_foo_json(struct kore_json_item** p_json,
                int i,
                double d,
                const char* psz,
                struct kore_json* p_json_payload) {   
    (*p_json) = kore_json_create_object(NULL, NULL);
    kore_json_create_integer_u64((*p_json),"i",i);
    kore_json_create_number((*p_json),"d",d);
    kore_json_create_string((*p_json),"psz",psz);
    if ( p_json_payload != NULL ) {
        struct kore_json_item* payload = kore_json_create_object((*p_json),"payload") ;
        struct kore_json_item* item;

        item = kore_json_find_integer_u64(p_json_payload->root,"idt") ;
        if ( item != NULL ) {
            kore_json_create_integer_u64(payload, "idt", item->data.u64) ;            
        }

        item = kore_json_find_string(p_json_payload->root,"msg") ;
        if ( item != NULL ) {
            kore_json_create_string(payload, "msg", item->data.string) ;            
        }
    }
}

int
api_get(struct http_request *req) {
    const char*              psz_header_get;
    struct kore_buf          buf;
    struct kore_json_item*   json;

    req->status = HTTP_STATUS_INTERNAL_ERROR;
    kore_buf_init(&buf, 512);

    printf("api_get begin\n");
    sleep(3);
    create_foo_json(&json, 1, 1*3.14, "API_GET", NULL);
    kore_json_item_tobuf(json, &buf);

    if ( http_request_header(req, "key_header_get", &psz_header_get) ) {
        http_response_header(req, "x-custom-header-get", psz_header_get);
    }
    
    req->status = HTTP_STATUS_OK;
    printf("api_get end\n");
    
    http_response(req, req->status, buf.data, buf.offset);
    kore_json_item_free(json);
    kore_buf_cleanup(&buf);
    return KORE_RESULT_OK;
}

int
api_post(struct http_request *req) {
    const char*              psz_header_post_1;
    const char*              psz_header_post_2;
    struct kore_buf          buf;
    struct kore_json_item*   json;
    struct kore_json         json_payload;

    req->status = HTTP_STATUS_INTERNAL_ERROR;
    kore_buf_init(&buf, 512);

    printf("api_post begin\n");
    sleep(3);
    kore_json_init(&json_payload, req->http_body->data, req->http_body->length);
    if ( kore_json_parse(&json_payload)) {
        create_foo_json(&json, 2, 2*3.14, "API_POST",&json_payload);
    } else {
        create_foo_json(&json, 2, 2*3.14, "API_POST",NULL);
    }
    kore_json_item_tobuf(json, &buf);

    if ( http_request_header(req, "key_header_post_1", &psz_header_post_1) ) {
        http_response_header(req, "x-custom-header-post-1", psz_header_post_1);
    }
    if ( http_request_header(req, "key_header_post_2", &psz_header_post_2) ) {
        http_response_header(req, "x-custom-header-post-2", psz_header_post_2);
    }

    req->status = HTTP_STATUS_OK;
    printf("api_post end\n");
    
    http_response(req, req->status, buf.data, buf.offset);
    kore_json_cleanup(&json_payload);
    kore_json_item_free(json);
    kore_buf_cleanup(&buf);
    return KORE_RESULT_OK;
}

int
api_put(struct http_request *req) {
    const char*              psz_header_put_1;
    const char*              psz_header_put_2;
    struct kore_buf          buf;
    struct kore_json_item*   json;
    struct kore_json         json_payload;

    req->status = HTTP_STATUS_INTERNAL_ERROR;
    kore_buf_init(&buf, 512);

    printf("api_put begin\n");
    sleep(3);
    kore_json_init(&json_payload, req->http_body->data, req->http_body->length);
    if ( kore_json_parse(&json_payload)) {
        create_foo_json(&json, 3, 3*3.14, "API_PUT",&json_payload);
    } else {
        create_foo_json(&json, 3, 3*3.14, "API_PUT",NULL);
    }
    kore_json_item_tobuf(json, &buf);

    if ( http_request_header(req, "key_header_put_1", &psz_header_put_1) ) {
        http_response_header(req, "x-custom-header-put-1", psz_header_put_1);
    }
    if ( http_request_header(req, "key_header_put_2", &psz_header_put_2) ) {
        http_response_header(req, "x-custom-header-put-2", psz_header_put_2);
    }

    req->status = HTTP_STATUS_OK;
    printf("api_put end\n");
    
    http_response(req, req->status, buf.data, buf.offset);
    kore_json_cleanup(&json_payload);
    kore_json_item_free(json);
    kore_buf_cleanup(&buf);
    return KORE_RESULT_OK;
}

int
api_delete(struct http_request *req) {
    const char*              psz_header_delete;
    struct kore_buf          buf;
    struct kore_json_item    *json;

    req->status = HTTP_STATUS_INTERNAL_ERROR;
    kore_buf_init(&buf, 512);

    printf("api_delete begin\n");
    sleep(3);
    create_foo_json(&json, 4, 4*3.14, "API_DELETE", NULL);
    kore_json_item_tobuf(json, &buf);

    if ( http_request_header(req, "key_header_delete", &psz_header_delete) ) {
        http_response_header(req, "x-custom-header-delete", psz_header_delete);
    }

    req->status = HTTP_STATUS_OK;
    printf("api_delete end\n");
    
    http_response(req, req->status, buf.data, buf.offset);
    kore_json_item_free(json);
    kore_buf_cleanup(&buf);
    return KORE_RESULT_OK;
}
