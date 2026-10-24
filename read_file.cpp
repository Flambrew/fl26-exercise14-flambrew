// read_file.cpp
#include <QFile>
#include <QDataStream>
#include <QDebug>

#include <cstdlib>

#include "file_header.h"

int main(int argc, char *argv[])
{
  QFile file("temp.dat");
  file.open(QIODevice::ReadOnly);
  QDataStream in(&file);

  // Read and check the header
  quint32 magic;
  in >> magic;
  if (magic != MAGIC){
    qDebug() << "Error: unexpected format.";
    return EXIT_FAILURE;
  }

  // Read the version
  qint32 version;
  in >> version;
  if(version != 1){
    qDebug() << "Error: unsupported file version.";
    return EXIT_FAILURE;
  }

  // use the same encoding format
  in.setVersion(QDataStream::Qt_5_0);

  // Read the data
  // QString msg;
  QList<QString> list;
  // in >> msg;

  QString temp;
  while (true) {
    in >> temp;
    if (!temp.isEmpty()) {
      list.append(temp);
    } else break;
  }

  QString outstring;
  qDebug() << "Read data from a file: ";
  for (int i = 0; i < list.length() - 1; ++i) {
    outstring.append(list.at(i) + " ");
  }
  qDebug() << outstring + list.last();
  
  return EXIT_SUCCESS;
}
