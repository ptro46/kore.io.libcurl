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
