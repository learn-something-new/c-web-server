#ifndef TWITTER_H
#define TWITTER_H

#include <QString>

class Twitter
{
public:
    Twitter();
    int parse(const QString reply, QString &token, QString &secret);
    int authorize();
};

#endif // TWITTER_H
