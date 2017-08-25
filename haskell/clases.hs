-- la funcion suma
suma::Int->Int->Int
suma x y = x + y

-- doble de un numero
doble::Float->Float
doble x = 2 * x

-- division exacta
divisionExacta::Float->Float->Float
divisionExacta x y | x == y = 1
							| x > y = 1 + divisionExacta (x-y) y
							| otherwise = 0

-- multiplicacion de dos numeros recursivamente
multiplicar::Float->Float->Float
multiplicar x y | y == 0 = 0
						| otherwise = x + multiplicar x (y - 1)

-- funcion que si es mayor que 0 devuelve la raiz cuadrado del mismo
-- caso contrario se le agrega 1
funcion1::Float->Float
funcion1 x | x > 0 = sqrt x
				| x < 0 = x + 1


-- maximo de dos numeros
maximo2::Float->Float->Float
maximo2 x y | x > y = x
				| otherwise = y

-- maximo de tres numeros version1
maximo3::Float->Float->Float->Float
maximo3 x y z | x >= y && x >= z = x
					| y >= x && y >= z = y
					| otherwise = z

-- maximo de tres numeros version2
maximo3v2::Float->Float->Float->Float
maximo3v2 x y z | maximo2 x y > z = maximo2 x y
						| otherwise  = z

-- conversiones de tipo
convierte :: Fractional a => Rational -> a
convierte x = fromRational x


-- verifica si es par con FP
par::Integral t => t -> Bool
par x = even x

-- succesor y antecesor de un numero
mm::Int->(Int,Int)
mm x = (x-1,x+1)

-- modulo de un vector
modul::(Float,Float)->Float
modul (x,y) = sqrt (x*x + y*y)






{-
	patrones constantes
	patrones para listas
	...
-}

--dado un vector de numeros retornar la suma
sumarVector::[Int]->Int
sumarVector [] = 0
sumarVector (x:xs) = x + sumarVector (xs)


-- fibonacci
fibo::Integer->Integer
fibo 0 = 0
fibo 1 = 1
fibo x = fibo(x-1) + fibo(x-2)

-- la lista  de fibonacci
listafibo::Integer->[Integer]
listafibo 0 = [fibo 0]
listafibo x = [fibo x ] ++ listafibo (x-1)

-- tamanhio de una lista
tamanhio::[Char]->Int
tamanhio [] = 0
tamanhio (x:xs) = 1 + tamanhio(xs)

-- un strimg es una lista de char's
tamanhioString::String->Int
tamanhioString "" = 0
tamanhioString (x:str) = 1 + tamanhioString str
 -- 3:40
 -- 4:40

-- agregando ita , example : juana ->juanita
--agregar::[Char]->String
--agregar (x:xs) | tamanhio xs == 1 = x ++ "ola"
-- | otherwise =



--funcion de descabezar
descabezar::[Int]->[Int]
descabezar (x:xs)  = xs


-- input [Int] que salga la cabeza
sacar2::[Int]->Int
sacar2 (x:xs) = x

-- problema de hanoi
hanooi::Int->Int
hanooi 1 = 1
hanooi n =  1 + 2 * (hanooi (n-1))

--tamanhio de un una lista de enteros
tamanhioInteger::[Int]->Int
tamanhioInteger [] = 0
tamanhioInteger (x:xs) = 1 + tamanhioInteger (xs)










-- segunda clase









--inversa
inversa::String->String
inversa [] = []
inversa (x:xs) = inversa xs ++ [x]

--palindromo
--palindromo::String->Bool
--palindromo str | inversa str == str = 1
--					| otherwise = 0

--funcion signo
--signo::Int->Int
--signo	x | x > 0 = 1
--			| x < 0 = -1
--			| x == 0 = 0


--factorial 0 = 1
--factorial x = x * factorial (x-1)

--combinacion
--combinacion::Integer->Integer->Integer
--combinacion n r = div (factorial (n))  (factorial(n-r) * factorial (r))

--fibonacci
fibonacci::Int->Int
--fibonacci signo  == -1 = 100
fibonacci 0 = 0
fibonacci 1 = 1
--fibonacci x = fibonacci (x-1) + fibonacci (x-2)
--fibonacci x | signo x == -1 = 0
--				| otherwise = fibonacci (x-1) + fibonacci (x-2)





--funcion matematica aleatoria
f::Float->Float
f x | x > 0 = sin x
		| x < 0 = x * (-1)
		| otherwise = 2





-- torres de hanoi recursivamente
hanoi::Integer->Integer
hanoi 1 = 1
hanoi x | x <= 0 = error "no se aceptan negativos ni ceros"
			|otherwise = 2 * hanoi(x-1) + 1


--factorial
factorial::Integer->Integer
factorial 0 = 1
factorial x | x < 0 = error "no negativos"
				| otherwise = x * factorial (x-1)

--combinatorio
combinatorio::Integer->Integer->Integer
combinatorio n r | (n >= r) && (r > 0) =  div (factorial n) (factorial(n-r)*factorial r)
						| otherwise = error "error la regla no se cumple la regla"



--raices de una funcion cuadratica
raices::Float->Float->Float->(Float,Float)
raices a b c | a > 0 && b^2 -4*a*c > 0 =  ( (-b + sqrt(b^2 -4*a*c)) /2*a , (-b - sqrt(b^2 -4*a*c)) /2*a )
					| otherwise = error "error dado o discriminante menor que cero"



--					| otherwise = (3.9, 4.0)


--tercera clase


--funcion aleatoria
first::(Char,Char,Char)->Char
first (x,y,z) = x

--listas de compresion
doblelista::[Int]->[Int]
doblelista xs = [ 2*x | x<-xs]

--que saque la lista de una lista de x>=0, condicion=filtro
listaraiz::[Float]->[Float]
listaraiz xs = [ sqrt(x) | x <- xs, x > 0]

--entra una lista de Int -> sumatoria

sumatoria::[Int]->Int
sumatoria xs = sum[ x*x | x<-xs ]
--sumatoria xs = sum[1,2]



--distancia entre dos puntos
type Punto = (Float,Float)
d ::Punto->Punto->Float
d (x,y) (m,n) = sqrt ((x-m)**2 + (y-n)**2 )


--
