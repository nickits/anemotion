/*
 * Copyright (C) 2011 Nicki, Bulgaria.
 *
 * See the LICENSE file for terms of use.
*/


#ifndef FRAME_H
#define FRAME_H

#include "defines.h"

class Frame
{
public:
  std::string name;
  std::string description;
  std::string url;
  dbo::ptr<Video> video;
  
  template<class Action> 
  void persist(Action& a)
  {
    dbo::field(a, name, "name");
    dbo::field(a, description, "description");	
    dbo::field(a, url, "url");
    dbo::belongsTo(a, video, "video");
  }
};

DBO_EXTERN_TEMPLATES(Frame);

#endif // FRAME_H
