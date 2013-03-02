/*

 Copyright (C) 2011 Nicki, Bulgaria.

 See the LICENSE file for terms of use.

*/

#ifndef ANEMOTION_H
#define ANEMOTION_H
#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include "datasession.h"

typedef std::pair<std::string, std::string> PairString;

class Anemotion : public cppcms::application
{
public:
  Anemotion(cppcms::service& srv);
  
  DataSession session_;
};

#endif // ANEMOTION_H
