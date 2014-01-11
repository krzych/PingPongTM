#include "training.h"
#include <QFile>
#include <QXmlStreamWriter>
#include <QMessageBox>

Training::Training()
{
    //hits= new QList<Hit>();
}

void Training::addHit(int pow, bool rot, int ang, int pos)
{
        hits.append(*(new Hit(pow,rot,ang,pos)));
}
void Training::serialize()
{
    QFile file("C://Parametry2.xml");
    file.open(QIODevice::WriteOnly);
    int i=0;
   QXmlStreamWriter *xmlWriter = new QXmlStreamWriter(&file);
    xmlWriter->writeStartDocument();
    xmlWriter->setAutoFormatting(true);
    xmlWriter->writeStartElement("Uderzenia");
    xmlWriter->writeAttribute("Ilosc", QString::number(hits.size()));

    for(int i=0;i<hits.size();i++)
    {

        xmlWriter->writeStartElement("Uderzenie");
        xmlWriter->writeTextElement("Sila",QString::number(hits.at(i).power));
        if(hits.at(i).rotation!=0)
        {
            xmlWriter->writeTextElement("Rotacja","Boczna");
        }
        if(hits.at(i).rotation==0)
        {
            xmlWriter->writeTextElement("Rotacja","Wsteczna");
        }
        xmlWriter->writeTextElement("Kat",QString::number(hits.at(i).angle));
        xmlWriter->writeTextElement("Pozycja",QString::number(hits.at(i).position));
        xmlWriter->writeEndElement();
    }
    xmlWriter->writeEndElement();
    xmlWriter->writeEndDocument();
    file.close();
}

void Training::deserialize()
{
    QFile file("C://Parametry3.xml");
    file.open(QIODevice::ReadOnly);
    if (!file.open(QIODevice::ReadOnly))
    {
        /*QMessageBox::critical(this,"QXSRExample::parseXML",
                              "Couldn't open example.xml",QMessageBox::Ok);*/
        return;
    }

    QXmlStreamReader *xmlReader = new QXmlStreamReader(&file);
    int hitsAmount;
    bool rotation;
    QString powerBuffer;
    QString rotationBuffer;
    QString angleBuffer;
    QString positionBuffer;


    while(!xmlReader->atEnd() && !xmlReader->hasError())
    {
        QXmlStreamReader::TokenType token = xmlReader->readNext();

        if(token==QXmlStreamReader::StartDocument)
        {
            continue;
        }

        if(token==QXmlStreamReader::StartElement)
        {
            if(xmlReader->name()=="uderzenia")
            {
                QXmlStreamAttributes attributes = xmlReader->attributes();
                if(attributes.hasAttribute("Ilosc"))
                {
                    //hitsAmount=attributes.value("Ilosc"));
                }
            }
            if(xmlReader->name()=="uderzenie")
            {
                while(!(xmlReader->tokenType() == QXmlStreamReader::EndElement &&
                        xmlReader->name() == "uderzenie"))
                {
                    if(xmlReader->name() =="Sila")
                    {
                        powerBuffer = xmlReader->text().toString();
                    }
                    if(xmlReader->name() =="Rotacja")
                    {
                        rotationBuffer = xmlReader->text().toString();
                    }
                    if(xmlReader->name() =="Kat")
                    {
                        angleBuffer = xmlReader->text().toString();
                    }
                    if(xmlReader->name() =="Pozycja")
                    {
                        positionBuffer = xmlReader->text().toString();
                    }
                    xmlReader->readNext();
                }
                if(rotationBuffer =="Bczna")
                {
                    rotation=1;
                }
                else
                {
                    rotation=0;
                }
                hits.append(*(new Hit(powerBuffer.toInt(),rotation,angleBuffer.toInt(),positionBuffer.toInt())));
            }
        }
    }
    xmlReader->clear();
    file.close();
}
