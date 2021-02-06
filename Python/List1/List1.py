#################################################   ZADANIE 1   #####################################################################

##Zadanie 1 (1 punkt). Napisz program, który dla zadanej liczby rzeczywistej a > 0 będącej długością
#krawędzi sześcianu obliczy i poda objętość kuli wpisanej w ten sześcian oraz pole jej powierzchni
#(tj. powierzchnię sfery). Użyj stosownego przybliżenia liczby π.

import math
print("ZADANIE 1 \n")
a = float(input("Podaj długość krawędzi sześcianu: "))
print("\n")

R = a * math.sqrt(2) / 2 #opisany
r = a  / 2  #wpisany
V = 3 * math.pi * math.pow(R, 3) / 4 #opisany
v = 3 * math.pi * math.pow(r, 3) / 4 #wpisany
Ppo = 4 * math.pi * math.pow(R, 2) #opisany
Ppw = 4 * math.pi * math.pow(r, 2) #wpisany

print("Objetość kuli wpisanej w podany sześcian wynosi: " + str(round(v, 2)) +".")
print("Pole powierzchni kuli wpisanej w podany sześcian wynosi: " + str(round(Ppw, 2)) +".\n")

print("Objetość kuli opisanej na podanym sześcianie wynosi: " + str(round(V, 2)) + ".")
print("Pole powierzchni kuli opisanej na podanym sześcianie wynosi: " + str(round(Ppo, 2)) + ".\n")

#################################################   ZADANIE 2   #####################################################################

#Zadanie 2 (1 punkt). Napisz program, który dla podanych liczb rzeczywistych x, y rozstrzyga, czy x + y 
#oraz x · y mają ten sam znak (+, − lub 0).

print("ZADANIE 2 \n")
x = float(input("Podaj x: "))
y = float(input("Podaj y: "))
suma = x + y
iloczyn = x * y
if suma > 0:
    print("Znak wykonanej sumy to '+'.\n")
elif suma == 0:
    print("Znak wykonanej sumy to '0'.\n")
else:
    print("Znak wykonanej sumy to '-'.\n")

if iloczyn > 0:
    print("Znak wykonanego iloczynu to '+'.\n")
elif iloczyn == 0:
    print("Znak wykonanego iloczynu to '0'.\n")
else:
    print("Znak wykonanego iloczynu to '-'.\n")

if((suma > 0 and iloczyn > 0) or (suma < 0 and iloczyn < 0) or (suma == 0 and iloczyn == 0)):
    print("Znaki wyników operacji x + y oraz x * y są takie same.\n")
else:
    print("Znaki wyników operacji x + y oraz x * y są różne.\n")

    
#################################################   ZADANIE 3   #####################################################################

#Zadanie 3 (1 punkt). Załóżmy, że pewna uczelnia prowadzi rekrutację według następujących zasad, w których kandydat
#jest punktowany na podstawie wyników matur z matematyki, fizyki i chemii (po jednym wyniku na przedmiot):
#(1) Kandydat dostaje się na studia wtedy i tylko wtedy, gdy zdobył w sumie co najmniej 220 punktów, z wyjątkiem 
#sytuacji opisanych w punktach (2) i (3).
#(2) Jeśli kandydat zdobył 0 punktów z jednego z przedmiotów, nie dostaje się, chyba że zdobył 100 punktów z jednego 
#z pozostałych przedmiotów i co najmniej 190 punktów w sumie - w takiej sytuacji dostaje się.
#(3) Kandydat, który uzyskał dodatnie punkty z każdego przedmiotu i uzyskał 100 punktów z co najmniej jednego z nich,
#dostaje się niezależnie od sumy punktów.
#Napisz program, który dla podanych liczb naturalnych wm, wf , wc z przedziału [0, 100] reprezentujących wyniki matur
#rozstrzyga, czy kandydat dostanie się na studia.

print("ZADANIE 3\nRekrutacja kandydata na studia \n")
matematyka = float(input("Podaj wynik maturalny z matematyki: "))
fizyka = float(input("Podaj wynik maturalny z fizyki: "))
chemia = float(input("Podaj wynik maturalny z chemii: "))
suma = matematyka + fizyka + chemia
flag = False
if(suma >= 220):
   flag = True
elif((matematyka == 0 or fizyka == 0 or chemia == 0) and (matematyka >= 100 or fizyka >= 100 or chemia >= 100) and suma >=  190):
    flag = True
elif((matematyka > 0 and fizyka > 0 and chemia > 0) and (matematyka >= 100 or fizyka >= 100 or chemia >= 100)):
    flag = True

if flag == True:
    print("Kandydat zostaje przyjęty na studia.\n")
else:  
    print("Kandydat nie zostaje przyjęty na studia.\n")

     
#################################################   ZADANIE 4   #####################################################################

#Zadanie 4 (1 punkt). Napisz program, który dla zadanej dodatniej liczby naturalnej n podaje ilość 
#naturalnych dzielników n różnych niż 2, 3 i 5.

print("ZADANIE 4 \n")
n = int(input("Podaj dodatnią liczbę naturalną: "))
ilość = 0
print("Dzielniki podanej liczby to: ", end = "")
for i in range(1, n+1):
    if i == n and n % i == 0 and i != 2 and i != 3 and i != 5:
        print(str(i), end = ". ")
        ilość += 1
    elif n % i == 0 and i != 2 and i != 3 and i != 5:
        if n == 2 or n == 3 or n == 5:
            print(str(i), end = ". ")
            ilość += 1
        else:
            print(str(i), end = ", ")
            ilość += 1

print("Łączna ilość dzielników to: " + str(ilość) + ".")
  










