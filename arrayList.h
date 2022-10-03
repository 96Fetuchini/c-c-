#include<iostream>
#include<cstdlib>

using namespace std;

template<class type>
class arrayList{
    private:
        bool empty;
        type *list;
        int currentSize; //actualk currentSize of the array
        int maxSize; //Max amount of ellements that the arrat can have
        int elemCount;//element elemCount
    public:
        arrayList(){
            list = NULL;
            elemCount = 0;
            currentSize = 0;
            empty = true;
        }
        arrayList(int elemCount){
            this->elemCount = elemCount;
        }
        /*
        arrayList(const arrayList<type>& al){
            currentSize = al.currentSize; 
            elemCount = al.elemCount;
            empty = al.empty;
            list = new type[currentSize];
            for(int i = 0; i < elemCount; i++)
                list[i] = al.list[i];
        }
        */
        ~arrayList(){
            free (list);
        }
        void expandSize(){
            type* aux = NULL;
            if(currentSize < 1)
                currentSize = 1;
            else
                currentSize = currentSize << 1; 
            list = (type*) realloc(list, sizeof(type) * currentSize);
            /*
            aux = new type[currentSize];
            if(0 < elemCount){
                for(int i = 0; i < elemCount; i++){
                    aux[i] = list[i];
                }
            }
            list = aux;
            delete [] aux; 
            */
        }
        void shrinkSize(){
            //cout << "alo" << endl;
            type* aux = NULL;
            if(1 < currentSize){
                currentSize = currentSize >> 1;
                aux = list;
                list = (type*) realloc(list, sizeof(type) * currentSize);
                /*
                aux = new type[currentSize];
                if(0 < elemCount){
                    for(int i = 0; i < elemCount; i++){
                        aux[i] = list[i];
                    }
                }
                list = aux;
                delete[] aux;
                */
            }
            else{
                if(0 < currentSize && list != NULL)
                    free(list);//delete [] list;
                list = NULL;
                empty = true;
            }
        }
        //capacity
        int getCurrentSize() const{
            return currentSize;
        }
        int getElemCount() const{
            return elemCount;
        }
        void resize(const int &n){
            /*
            function that add n units of space to the array
            */ 
            if(currentSize < n){
                while(currentSize < n){
                    expandSize();
                }
            }
            else{
                while(n < currentSize && n <= currentSize >> 1)
                    shrinkSize();
            }
            if(elemCount < n){
                for(int j = elemCount; j < n; j++)
                    list[j] = 0;
            }
            elemCount = n;
        }
        void reserve(const int &i){
            resize(i + elemCount);
        }
        void moveElementsForward(const int &i, const int &n){
            for(int j = 0; j <= n; j++){
                list[elemCount - j] = list[i + n - j];
                list[i + n - j] = 0;
            }
        }
        void moveElementsBackward(const int &i, const int &n){
            for(int j = i; j < elemCount - 1; j++)
                list[j] = list[j + n];
        }
        void gap(const int &i, const int &n = 1){
            if(-1 < i){
                if(elemCount < (i + n))
                    resize(i + n);
                else
                    resize(elemCount + n);
                moveElementsForward(i, n);  
            } 
        }
        void crease(const int &i, const int &n = 1){
            if(-1 < i){
                moveElementsBackward(i , n);
                if(elemCount < (i+n)){
                    resize(i);
                }
                else{
                    resize(elemCount - n);
                }  
            } 
        }
        bool isEmpty() const{
            return empty;
        }
        //access
        type getFirst()const{
            if(1 < elemCount)
                return list[0];
            else
                return list[0];
        }
        type getLast() const{
            if(1 < elemCount)
                return list[elemCount - 1];
            else
                return list[0];
        }
        type& at(const int &i){
            return list[i % elemCount];
        }
        type& operator [](const int &i) {
            return at(i);
        }
        void print() const{
            if(!empty){    
                cout << "[";
                for(int i = 0; i < elemCount - 1; i++){
                    cout << list[i] << ", ";
                }
                cout << list[elemCount - 1] << "]" <<endl;
            }
        }
        const int search(const type& elem){
            for(int i = 0; i < elemCount; i++){
                if(list[i] == elem)
                    return i;
            }
            return -1;
        }
        //Modifiers      
        void push(const type &elem){
            if(elemCount == currentSize){
                //cout << elemCount << endl;
                expandSize();
            }
            list[elemCount] = elem;
            elemCount = elemCount + 1;
            empty = false;
        }
        type pop(){
            elemCount = elemCount - 1;
            type val = list[elemCount];
            if(elemCount == currentSize >> 1)
                shrinkSize();
            return val;
        }
        void insert(const int &i, const type &elem){
            if(-1 < i){
                gap(i);
                list[i] = elem;
            }
        }
        void erase(const int &i){
            if(-1 < i && i < elemCount){
                list[i] = 0;
                crease(i);
            }
        }
        void insert(const arrayList<type> &al, int i){
            if(-1 < i){
                int alcount = al.getElemCount();
                gap(i, alcount);
                for(int j = i; j = i + alcount; i++)
                    list[i] = al[j - i];
            }
        }
        void concatenate(arrayList<type> &al){
            for(int i = 0; i < al.getElemCount(); i++)
                push(al[i]);
        }
        arrayList<type>& operator +(arrayList<type> &al){
            concatenate(al);
            return *this;
        }
        /*
        void swap(arrayList<type> &al){
            arrayList<type> aux = al;
            al = *this;
            *this = aux;
        }
        */
};
