#include <QCoreApplication>
#include <QVector>
#include <iostream>
#include <QTextCodec>

template<typename T>
void printVector(const std::vector<T>& vct){
    for(unsigned int i = 0; i < vct.size(); ++i){
        std::cout << vct[i] << ",";
    }
    std::cout << std::endl;
}

template<typename T>
void bubbleSort(std::vector<T>& array){
    if(array.size() < 2)
        return;
    bool swaped = false;
    int count = 0;
    do{
        std::cout << "   " << QString("--%1--").arg(++count).toStdString() << std::endl;
        swaped = false;
        for(auto it = array.begin(); (it+1) != array.end(); ++it){
            auto current = it;
            auto next = it + 1;
            if(*current > *next){
                swaped = true;
                std::swap(*current, *next);
            }
            std::cout << "       " << QString("----%1----").arg(it - array.begin() + 1).toStdString();
            printVector(array);
        }
    }while(swaped /*&& count < (src.size() - 1)*/);
    return;
}

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    //使用QVector 便于打印
    std::vector<int> array{98, 58, 56, 32, 22, 10, 1};
    std::cout << "src:";
    printVector(array);
    bubbleSort(array);
    std::cout << "dest:";
    printVector(array);
    return a.exec();
}
