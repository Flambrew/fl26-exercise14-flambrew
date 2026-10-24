// write_file.cpp
#include <QFile>
#include <QDataStream>
#include <QDebug>
#include <QList>

#include "file_header.h"
  
int main(int argc, char *argv[])
{
  QFile file("temp.dat");
  file.open(QIODevice::WriteOnly);

  // treat the file as consuming a data stream
  QDataStream out(&file);

  // Write a header with a magic number and a version
  out << MAGIC;
  out << VERSION;

  // use a specific streaming format
  out.setVersion(QDataStream::Qt_5_0);
  
  // write some data
  // QString msg = "This is a test. This is only a test.";
  QList<QString> list; // the instructions for this assignment are incredibly unclear and thus this is my best assumption of what we are supposed to do. 

  list.append("This");
  list.append("is");
  list.append("a");
  list.append("test.");
  list.append("This");
  list.append("is");
  list.append("only");
  list.append("a");
  list.append("test.");
 
  for (int i = 0; i < list.length() - 1; ++i) {
    out << (list.at(i) + " ");
  }
  out << list.last();
  
  // notify the user that we're finished
  qDebug() << "A data stream has been written to a file.";  
  
  return EXIT_SUCCESS;
}
