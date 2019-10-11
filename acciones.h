using namespace std;

vector<char> rellenarVector(int cantidad){
    vector<char> arreglo;
    for (size_t i = 0; i < cantidad; i++)
    {
       arreglo.push_back('*');
    }
    return arreglo;
}

void rellenarMatriz(vector<vector<char>>& matriz,int cantidad){
     cantidad += cantidad % 2 == 0 ? 0 : 1 ;
    for (size_t i = 0; i < cantidad; i++)
    {
        matriz.push_back(rellenarVector(cantidad));
    } 
}

void imprimirMatriz(vector<vector<char>> matriz){
    for (size_t i = 0; i < matriz.size(); i++)
    {
       for (size_t j = 0; j < matriz[i].size(); j++)
       {
           cout << matriz[i][j] << " ";
       }
       cout<<endl;
    }
    
}

void actualizarMatriz(vector<vector<char>>& matriz,vector<int> coord){
    for (size_t i = 0; i < matriz.size(); i++)
    {
       for (size_t j = 0; j < matriz[i].size(); j++)
       {
           if(j == coord[0] && i == coord[1])
           {
               matriz[i][j] = '0';
               return;
           }   
       } 
    }
}

void dibujar(queue<vector<int>> cola,vector<vector<char>> matriz){
    while(!cola.empty()){
        actualizarMatriz(matriz,cola.front());
        cola.pop();
    }
    imprimirMatriz(matriz);
}

vector<int> nuevas_coord(int x,int y){
    vector<int> coordenadas = {x,y};
    return coordenadas;
}

queue<vector<int>> linea(int x1, int y1, int x2, int y2){
    queue<vector<int>> cola_coord;
	int xf, xi, yf, yi,aux,opc,p,a,b;
	int dx = x2-x1;
	int dy = y2-y1;
	if((dx*dy) < 0){aux = -1;}
	else{ aux = 1; }
	cola_coord.push(nuevas_coord(x1,y1));

	if((dx < 0 && dy < 0) || (dx < 0 && dy > 0))
	{   xf = x1; xi = x2;
	    yf = y1; yi = y2;
	}else{
		xf = x2; xi = x1;
		yf = y2; yi = y1;}
	dx = abs(dx);
	dy = abs(dy);
	if(dy > dx)
	{ 	a = 2*dx;	b = 2*(dx-dy);
		opc = 2;    p = 2*dx - dy;
	}else{
		a = 2*dy;   b = 2*(dy-dx);
		opc = 1;	p = 2*dy - dx;
	}

	if(opc == 1){
		while(xi < xf){
			if(p<0){
				xi++; p+=a;
			}else{
				xi++; p+=b;
				yi+=aux;
			}
			cola_coord.push(nuevas_coord(xi,yi));
		}
	}else{
		while(yi < yf)	{
			if(p<0){
				yi+=aux; p+=a;
			}else{
				xi++; p+=b;
				yi+=aux;
			}
			cola_coord.push(nuevas_coord(xi,yi));
		}
	}
    return cola_coord;
}
