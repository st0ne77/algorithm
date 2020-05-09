#include <QCoreApplication>
#include <QVector>
#include <QDebug>
template<typename T>
std::vector<T> bubbleSort(std::vector<T> src){
    if(src.size() < 2)
        return src;
    bool swaped = false;
    do{
        swaped = false;
        for(auto it = src.begin(); (it+1) != src.end(); ++it){
            auto current = it;
            auto next = it + 1;
            if(*current > *next){
                swaped = true;
                std::swap(*current, *next);
            }
        }
    }while(swaped);
    return src;
}

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    //使用QVector 便于打印
    QVector<int> src{10,1,35,61,89,36,55};
    qDebug() << "src:" << src;
    std::vector<int> dest = bubbleSort(src.toStdVector());
    qDebug() << "dest:" <<QVector<int>::fromStdVector(dest);
    return a.exec();
}
