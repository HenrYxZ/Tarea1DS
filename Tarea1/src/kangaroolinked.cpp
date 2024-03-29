// Class automatically generated by Dev-C++ New Class wizard
#include "node.h"
#include "kangaroolinked.h" // class's header file
#include <sstream>
// class constructor
kangarooLinked::kangarooLinked()
{
    _size=0;
	_first=NULL;
	// insert your code here
}

// class destructor
kangarooLinked::~kangarooLinked()
{
	// insert your code here
}
kangarooLinked::kangarooLinked(const kangarooLinked &kSource)
{
    _first = new node(kSource._first->getData());
    _size = kSource._size;
    node *current=kSource._first;
    int i=1;
    while(current->getNext()!=NULL)
    {
        kangaroo currentCopy= current->getData();
        this->add(i,currentCopy);
        i++;
    }
}
kangarooLinked& kangarooLinked::operator= (const kangarooLinked &kSource)
{
    _first = new node(kSource._first->getData());
    _size = kSource._size;
    node *current=kSource._first;
    int i=1;
    while(current->getNext()!=NULL)
    {
        kangaroo currentCopy= current->getData();
        this->add(i,currentCopy);
        i++;
    }
    return *this;
}
ostream& operator<< (ostream& out, const kangarooLinked& k)
{
    
    node *current;
    current=k._first;
    string fila;
          for(int i=0;i<k._size;i++){
         ostringstream os;   
         double dd = current->getData().getJump();
         os << dd;
         string str = os.str();
        
      
string pos;
stringstream out2;
out2 << i;
pos = out2.str();
        
        
         
         fila = fila +"("+pos+") "+current->getData().getName() + "\t" + str+"\n";
         current=current->getNext();
         }
         out << fila;
         return out;
}


int kangarooLinked::size()
{
	
	return _size;


}


bool kangarooLinked::isEmpty()
{
	bool empty;
	if(_size==0)
	{
		empty=true;
	}
	else
	empty=false;
	return empty;


}

void kangarooLinked::add(int position, kangaroo k)
{

	int size=this->size();

	if(_first==NULL)//primer elemento a agregar
	{
		node* neoNode= new node(k);
		_first=neoNode;
		_size++;

		return;
	}


	if(position==0)//primera posicion
	{

		node* neoNode= new node(k);
		neoNode->setNext(_first);
		_first=neoNode;
		_size++;
		return;
	}
	
	if(position==size-1)//ultimo
	{

		node* neoNode= new node(k);
		node* current=_first;
		for (int i=0; i<position-1; i++) {
			current=current->getNext();
		}
		current->setNext(neoNode);
		_size++;
		return;
		
	}else{//si est� entre medio

		node* neoNode= new node(k);
		node* current=_first;
		node* previous;
		for (int i=0; i<position; i++) {
			previous=current;
			current=current->getNext();
		}
		previous->setNext(neoNode);
		neoNode->setNext(current);
		_size++;
		return;
	}
	
	
} 

kangaroo kangarooLinked::get(int position)
{
	int limite=this->size();


	if(position<limite){

		node* current=_first;

		for (int i=0; i<position; i++) {
			current=current->getNext();
			
		}
		
		return current->getData();
	}

} 

void kangarooLinked::remove(int position)
{
	if(_size<1)
	{
		cout<<"<<LISTA VACIA>> --->|No es posible eliminar|"<<endl;
		return;
	}
	else{
		if(position==0)//primero
		{
			
			
            
			node* aux=_first->getNext();
			kangaroo kang=_first->getData();
			string nombre=kang.getName();
			
			delete _first;
			_first=aux;
			
			_size--;

			
		}
		if(position==_size-1)//ultimo
		{cout<<"elimina ultimo"<<endl;
			node* current=_first;
			node* previous;
			for (int i=0; i<position-1; i++) {
				previous=current;
				current=current->getNext();
				
			}
			node* toRemove=current->getNext();
			current->setNext(0);
			delete toRemove;
			_size--;
			
			
			
		}else{//si est� entre medio
			node* current=_first;
			node* previous;
			for (int i=0; i<position; i++) {
				previous=current;
				current=current->getNext();
				
			}
			node* toRemove=current;
			previous->setNext(current->getNext());
			delete current;
			_size--;
		}
		
	}
} 



