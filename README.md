# 2019_MicroMouse

# Robot, znajdujący czarne pole na wyznaczonym dla niego białym obszarze

Projekt powstał, by z wykorzystaniem miktokontrolera STM32F407VG DISCOVERY, czujników odległości oraz pary silników autonomicznie poruszający się pojazd samodzielnie dojechał do wyznaczonego celu.
Robot zasilany jest dwoma akumulatorami 3.6V, co daje napięcie 7.2V dla silników, oraz 5V dla mikrokontrolera i urządzeń peryferyjnych dzięki zastosowaniu stabilizatora napięcia.

# Budowa Robota
Szkielet urządzenia został zapożyczony z innego robota, który zaopatrzony był w dwa sprawne koła, a jego budowa pozwalała na obrót w miejscu.
Silniki, które zamontowaliśmy obsługujemy za pomocą mostku H oraz sygnałów PWM z mikrokontrolera, dzięki czemu robot może jechać do przodu, do tyłu oraz skręcać w miejscu i w ruchu.
Dzięki trzem czujnikom odległości robot jest świadom dystansu do ściany przed nim, oraz do dwóch bocznych, a czunik światła, zlokalizowany na spodzie dostarcza mu informacji o ilości światła zaabsorbowanego przez podłogę.
Ta funkcjonalność, wraz z podstawowym algorytmem przeszukiwania danego obszaru pozwoliła na stworzenie maszyny, która zatrzyma się na polu, któro jest czarne.

# Wnętrze Miktokontrolera
Elementy płytki, które wykorzystaliśmy, to oprócz kilku pinów wejścia/wyjścia trzy timery:
- zwiększający daną zmienną co 10 mikrosekund, używaną do bardzo precyzyjnych pomiarów czasu sygnału na wejściu,
- obsługujący sygnały wyzwalające do czujników o długości 10 mikrosekund, co 100 milisekund,
- generujący sygnały PWM dla silników
By czujnik światła poprawnie działał potrzebny był nam jeden przetwornik analogowo-cyfrowy.

# Wykorzystany Kod
Kod, który napisaliśmy składa się z czterech elementów:
- obsługi przerwać timerów,
- odczytu danych z czujników,
- dostosowaniu ruchu robota do jego położenia w przestrzeni,
- odczytu danych z czujnika światła i w przypadku dojechania do celu zatrzymanie robota

# Kompilacja i uruchomienie projektu:
- 1. W przypadku niedostatecznego zasilania wymiana wyładowanych akumulatorów ze spodu robota,
- 2. Podłączenie wszystkich pinów do mikrokontrolera zgodnie ze schematem zawartym w pliku "The_Final_Rob/The_Final_Rob.ioc",
- 3. Umieszczenie czarnego obszaru w przygotowanej do tego celu białej arenie,
- 4. Umieszczenie robota na arenie w dowolnym miejscu,
- 5. Zresetowanie robota za pomocą czarnego i uruchomienie za pomocą niebieskiego przycisku na płytce,
- W przypadku nieprawidłowego zakończenia działania powtórzyć kroki 4 i 5.

## Wykorzystane Elementy:
- mikrokontroler STM32F407VG DISCOVERY
- Mostek H TB6612FNG,
- dwa akumulatory INR18650-25R 3.6V,
- stabilizator napięcia Pololu D24V6F5 5V 0.6A,
- trzy ultradźwiękowe czujniki odległości HC-SR04,
- analogowy czujnik światła DFRobot Gravity

# Ulepszenia w przyszłości
Zamontowanie w robocie silników z enkoderami tak, by był on w stanie prouszać się w linii prostej oraz zaimplementowanie w nim algorytmu, który znajduje najkrótszą trasę w labiryncie

# Licencja
MIT

## Twórcy:
- Paulina Drozda
- Kacper Chrul

The project was conducted during the Microprocessor Lab course held by the Institute of Control and Information Engineering, Poznan University of Technology.
Supervisor: Tomasz Mańkowski

