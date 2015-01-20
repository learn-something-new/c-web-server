#ifndef TWITTER_H
#define TWITTER_H

#include <QString>

class Twitter
{
public:
    Twitter();
    int authorize();
    QString search();
private:
    int parse(const char *reply, QString &token, QString &secret);
    QString t_key;
    QString t_secret;
    const QString request_token_uri;
    const QString access_token_uri;
    const QString test_call_uri;
    const QString c_key;
    const QString c_secret;
};

#endif // TWITTER_H
