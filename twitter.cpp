#include "twitter.h"

#include <iostream>
#include <QVariant>
#include <oauth.h>

Twitter::Twitter():
    request_token_uri("https://api.twitter.com/oauth/request_token"),
    access_token_uri("https://api.twitter.com/oauth/access_token"),
    test_call_uri("https://api.twitter.com/1.1/search/tweets.json?q=%23halifax"),
    c_key("iob3KXGiF9Lwx6U1ziFSQGzRy"),
    c_secret("J4tPj5CSY2a4OwMyDkJjHLLLVFs673x2GerXNxCZwFoVUwy2zp")
{
    std::cout << "Initalizing Twitter..." << std::endl;
}

int Twitter::parse(const char *reply, QString &token, QString &secret)
{
    int rc;
    int ok = 1;
    char **rv = NULL;

    rc = oauth_split_url_parameters(reply, &rv);
    qsort(rv, rc, sizeof(char *), oauth_cmpstringp);

    if( rc==3
        && !strncmp(rv[1],"oauth_token=",11)
        && !strncmp(rv[2],"oauth_token_secret=",18) )
    {
      ok=0;
      token = rv[1];
      secret = rv[2];

      token = token.mid(12);
      secret = secret.mid(19);
    }

    if(rv)
    {
        free(rv);
    }

    return ok;
}

QString Twitter::search()
{
    t_key    = "13948782-1eSu5SfwluxVU6tgfb8FCjn96ED2KacV2zibHeSkW";
    t_secret = "XII42ewjRAXhk9ijWwIUf6eYaivwWLqXcsWCoqEEwJh92";

    char *req_url = NULL;
    char *postarg = NULL;
    char *reply   = NULL;

    std::cout << "Requesting search data..." << std::endl;

    req_url = oauth_sign_url2(test_call_uri.toLocal8Bit().constData(),
                              NULL,
                              OA_HMAC,
                              NULL,
                              c_key.toLocal8Bit().constData(),
                              c_secret.toLocal8Bit().constData(),
                              t_key.toLocal8Bit().data(),
                              t_secret.toLocal8Bit().data());

    reply = oauth_http_get(req_url, postarg);

    std::cout << "query: " << req_url << std::endl;


    if(req_url)
    {
        free(req_url);
    }

    if(postarg)
    {
        free(postarg);
    }
    return(reply);
}

int Twitter::authorize()
{
    char *req_url = NULL;
    char *postarg = NULL;
    char *reply   = NULL;

    req_url = oauth_sign_url2(request_token_uri.toLocal8Bit().constData(),
                              &postarg,
                              OA_HMAC,
                              NULL,
                              c_key.toLocal8Bit().constData(),
                              c_secret.toLocal8Bit().constData(),
                              NULL,
                              NULL);

    reply = oauth_http_post(req_url, postarg);

    std::cout << "query: " << req_url << std::endl;

    if (req_url)
    {
        free(req_url);
    }

    if (postarg)
    {
        free(postarg);
    }

    if (!reply)
    {
        return(3);
    }

    int parse_reply = parse(reply, t_key, t_secret);

    if (parse_reply)
    {
        return(4);
    }

    if (reply)
    {
        free(reply);
    }

    return(0);
}
