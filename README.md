# opdracht2AP
Opdracht 2 van AP. De opdracht is Opgebouwd uit een UML diagram en vervolgens verbeterd op compile errors. Toen alle files konden compilen is het executable file uitgevoerd en wederom zijn er weer fouten uit gehaald. Nadat alles vallide c++ code was, zijn er testen uitgevoerd op de code die keken of de inhoud van de code ook doet wat het zou moeten doen. Na deze testen, zijn de fouten verbeterd en werkt alles. Veel tussen stappen zijn appart gecommit in de github file, en dus zijn oudere versies terug te vinden.

# main.cpp
In de main.cpp staat code die enkele functies demonstreert. Ook is deze met comments uitgelegd in de code. Veel gebruikte methodes hiervaan worden ook laten zien in de test_vector.cpp file. Het doel hiervan is het laten zien dat alles werkt naar behoren.

# tes_vector.cpp / catch.hpp
Voor de testen die uitgevoerd moesten worden op het programma is een speciale framework gebruikt "catch 2". Dit framework maakte het makelijker om methodes te testen, En gaf hierbij ook overzichtelijke feedback.

# warehouse.cpp/.hpp
Alle informatie uit het complete programma komt samen in de warehouse klasse. Deze staat geschreven in de warehouse header en source file. Objecten van de warehouse klasse hebben twee attributen: een vector met shelves en een vector met employees.

# employee.cpp/.hpp
Een warehouse object kan dus tot meerdere employees beschikken. Een employee object zelf heeft ook enkele attributen. Deze bestaat namelijk uit naam, een bezig-status en uit een zogehete "forklift certificate". Dit laatste bepaalt of de employee bepaalde take

# opslag.cpp/.hpp
In de opslag file worden zowel de shelf klasse als de pallet klasse gemaakt. Maar eerst wordt er een interface gescreëerd. Dit interface beschikt twee methodes: isFull en isEmpty. Deze twee methodes worden beide gebruikt in de shelf klasse en de pallet klasse. Het warehouse kan beschikken over shelves. Een shelf heeft vier opslag plekken voor pallets. Een pallet bestaat uit een naam van het product, een maximale hoelveelheid opslag en het aantal dat opgeslagen ligt

