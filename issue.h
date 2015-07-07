// Copyright 2015, Promtehaero.
// All rights reserved.
//
// Software license
//
// Author: dandemidow@gmail.com (Danila Demidow)
//
// Promtehaero VoIP Project

#ifndef ISSUE
#define ISSUE

#include <QString>
#include "types.h"

struct Issue {
  unsigned int id;
  IdType project;
  IdType tracker;
  IdType status;
  IdType priority;
  IdType author;
  QString subject;
  QString description;
  QString start_date;
  QString due_date;
  unsigned int done_ratio;
  QString estimated_hours;
  QString created_on;
  QString updated_on;
  QString closed_on;

};

#endif // ISSUE

