#include "twitter.h"

#include <QVariant>
#include <oauth.h>

Twitter::Twitter()
{
}

int Twitter::parse(const QString reply, QString &token, QString &secret)
{
    int rc;
    int ok=1;
    char **rv = NULL;

    rc = oauth_split_url_parameters(reply.toLocal8Bit().data(), &rv);
    qsort(rv, rc, sizeof(char *), oauth_cmpstringp);

    if( rc==2
        && !strncmp(rv[0],"oauth_token=",11)
        && !strncmp(rv[1],"oauth_token_secret=",18) )
    {
      ok=0;
      token = rv[0][12];
      secret = rv[1][19];
    }

    if(rv) free(rv);
    return ok;
}

int Twitter::authorize()
{
    const QString request_token_uri = "https://api.twitter.com/oauth/request_token";
    const QString access_token_uri = "https://api.twitter.com/oauth/access_token";
    const QString test_call_uri = "https://api.twitter.com/1.1/";
    const QString c_key         = "iob3KXGiF9Lwx6U1ziFSQGzRy"; //< consumer key
    const QString c_secret      = "J4tPj5CSY2a4OwMyDkJjHLLLVFs673x2GerXNxCZwFoVUwy2zp"; //< consumer secret

    QString t_key    = "13948782-1eSu5SfwluxVU6tgfb8FCjn96ED2KacV2zibHeSkW"; //< access token key
    QString t_secret = "XII42ewjRAXhk9ijWwIUf6eYaivwWLqXcsWCoqEEwJh92"; //< access token secret

    char *req_url = NULL;
    char *postarg = NULL;
    char *reply   = NULL;

    printf("Request token..\n");

    req_url = oauth_sign_url2(request_token_uri.toLocal8Bit().constData(),
                              &postarg,
                              OA_HMAC,
                              NULL,
                              c_key.toLocal8Bit().constData(),
                              c_secret.toLocal8Bit().constData(),
                              NULL,
                              NULL);

    reply = oauth_http_post(req_url, postarg);

    printf("query:'%s'\n",req_url);
    printf("reply:'%s'\n",reply);

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

    if (parse(reply, t_key, t_secret))
    {
        return(4);
    }

    if (reply)
    {
        free(reply);
    }

    req_url = oauth_sign_url2(test_call_uri.toLocal8Bit().constData(),
                              &postarg,
                              OA_HMAC,
                              NULL,
                              c_key.toLocal8Bit().constData(),
                              c_secret.toLocal8Bit().constData(),
                              t_key.toLocal8Bit().constData(),
                              t_secret.toLocal8Bit().constData());

    reply = oauth_http_post(req_url, postarg);

    printf("query:'%s'\n",req_url);
    printf("reply:'%s'\n",reply);

    if(req_url)
    {
        free(req_url);
    }

    if(postarg)
    {
        free(postarg);
    }

    if (strcmp(reply,"bar=baz&method=foo+bar"))
    {
        return (5);
    }

    return(0);
}
