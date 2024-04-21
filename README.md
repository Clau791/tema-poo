Pentru tema 2 am folosit impartirea prin header-e, concepte de mostenire pentru clase CameraEco si CameraVip, destructor virtual,functii si variabile static, am incercat sa folosesc try si catch in main.cpp.Nu am reusit sa folosesc down_casting si clasa abstracta .Am vrut sa folosesc down casting pentru a verifica daca camera aleasa este Eco sau VIP astfel :
              Camera& cameraSelectata = camere[indexCamera];
              CameraEco* cameraEco = dynamic_cast<CameraEco*>(&cameraSelectata);
              CameraVIP* cameraVIP = dynamic_cast<CameraVIP*>(&cameraSelectata);
Dupa care se facea o verificare si se afisau detalii in functie de tipul camerei
Dar mereu imi returna nullptr probabil din cauza faptului ca nu am adaugat camere in vector corect, asa ca am renuntat la idee.
Pentru folosirea unei clase abstracte a trebuit sa transform clasa camera in clasa pur virtuala dar asta a insemnat sa nu pot instantia obiecte clasei de baza ceea ce mi-a incurcat si mai mult programul asa ca am renuntat si la asta.



Aplicatie pentru rezervarea unei camere de hotel dintr-un oras ales.

Utilizatorul poate vedea hotelurile din orasul selectat .Hotelurile au diferite tipuri de camere cu dimensiuni diferite si pret diferit.Acestea pot fi deja ocupate sau se pot ocupa de utilizator.Dupa rezervarea unei camera utilizatorul poate sa rezerve alta camera daca doreste(camera pe care a rezervat-o anterior o sa figureze ca fiind ocupata).