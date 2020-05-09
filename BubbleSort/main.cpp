#include <QCoreApplication>
#include <QVector>
#include <QDebug>
#include <QTextCodec>
template<typename T>
std::vector<T> bubbleSort(std::vector<T> src){
    if(src.size() < 2)
        return src;
    bool swaped = false;
    int count = 0;
    do{
        qDebug() << "   " << QString("--%1--").arg(++count);
        swaped = false;
        for(auto it = src.begin(); (it+1) != src.end(); ++it){
            auto current = it;
            auto next = it + 1;
            if(*current > *next){
                swaped = true;
                std::swap(*current, *next);
            }
            qDebug() << "       " << QString("----%1----").arg(it - src.begin() + 1) << QVector<T>::fromStdVector(src);
        }
    }while(swaped /*&& count < (src.size() - 1)*/);
    return src;
}

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    //使用QVector 便于打印
    QVector<int> src{98, 58, 56, 32, 22, 10, 1};
    qDebug() << "src:" << src;
    std::vector<int> dest = bubbleSort(src.toStdVector());
    qDebug() << "dest:" <<QVector<int>::fromStdVector(dest);
    return a.exec();
}
