# kore.io.libcurl
how to make kore_curl calls between two kore.io backends

# kore-backend-2
this backend exposes 4 REST services

## get /api

the api_get handler will create a json returned in body, read a key_header_get header and return it in the x-custom-header-get header

## post /api

the api_post handler will create a json returned in body and process the one received by adding it in the returned json, read two headers key_header_post_1 and key_header_post_2 and return them respectively in the headers x-custom-header-post-1 x-custom-header -post-1

## put /api

the api_put handler will create a json returned in body and process the one received by adding it to the returned json, read two headers key_header_put_1 and key_header_put_2 and return them respectively in the headers x-custom-header-put-1 x-custom-header -put-1

## delete /api

the api_delete handler will create a json returned in body, read a key_header_delete header and return it in the header x-custom-header-delete

# kore-backend-1

this backend exposes 6 REST services

## get /req1

the call_get_req_1 handler will make the get /api call to the kore-backend-2

## get /req2

the call_get_req_2 handler will make the post /api call to the kore-backend-2, so it creates a json in body

## get /req3

the call_get_req_3 handler will make the put /api call to the kore-backend-2, so it creates a json in body

## get /req4

the call_get_req_4 handler will make the get /api call to the kore-backend-2

## get /req1_2

the handler call_get_req_1_2 will make the get /api call and if successful post /api to the kore-backend-2, so it creates a json in body

## get /req1_2_3_4

the call_get_req_1_2_3_4 handler will make the get /api, post /api, put /api and delete /api calls to the kore-backend-2.
it therefore sends the json in payload to the post and put calls, and it adds headers to each request so that these are returned.

# examples d'appels

# curl 

```bash
$ curl -i -k -X GET  https://127.0.0.1:8887/req1_2_3_4
HTTP/1.1 200 OK
server: kore (master-23d762d6)
connection: keep-alive
keep-alive: timeout=20
strict-transport-security: max-age=31536000; includeSubDomains
content-length: 581

{"payload_get":{"i":1,"d":3.140000,"psz":"API_GET"},"payload_post":{"i":2,"d":6.280000,"psz":"API_POST","payload":{"idt":1,"msg":"string message POST"}},"payload_put":{"i":3,"d":9.420000,"psz":"API_PUT","payload":{"idt":2,"msg":"string message PUT"}},"payload_delete":{"i":4,"d":12.560000,"psz":"API_DELETE"},"x-custom-header-get":"value_header_get","x-custom-header-post-1":"value_header_post_1","x-custom-header-post-2":"value_header_post_2","x-custom-header-put-1":"value_header_put_1","x-custom-header-put-2":"value_header_put_2","x-custom-header-delete":"value_header_delete"}
```

# traces de kore-backend-1

```bash
kore-backend-1 :: begin :: call get /req_1_2
kore-backend-1 call GET https://localhost:8888/api
kore-backend-1 call POST https://localhost:8888/api
kore-backend-1 call PUT https://localhost:8888/api
kore-backend-1 call DELETE https://localhost:8888/api
kore-backend-1 :: end :: call get /req_1_2
```

# traces de kore-backend-2

```bash
api_get begin
api_get end
api_post begin
api_post end
api_put begin
api_put end
api_delete begin
api_delete end
```
