/*

 Copyright (C) 2011 Nicki, Bulgaria.

 See the LICENSE file for terms of use.

*/

#include "datasession.h"
#include "model/defines.h"
#include <iostream>

DataSession::DataSession(): connection_("data.db")
{
  initialize();
}

void DataSession::initialize()
{
    setConnection(connection_);
    
    mapClass<User>("User");
    mapClass<Image>("Image");
    mapClass<Video>("Video");
    mapClass<Frame>("Frame");

    try{
      dbo::Transaction t(*this);
      
      createTables();
      
      t.commit();
      
      std::cerr << "Database created";
    }
    catch(std::exception e){
      std::cerr << e.what() << std::endl;
      //std::cerr << "Using existing database";
    }
}

