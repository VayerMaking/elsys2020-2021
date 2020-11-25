DROP DATABASE IF exists Parking;
CREATE DATABASE Parking;
USE Parking;

CREATE TABLE Person(
  id int primary key not null auto_increment,
  name varchar(100) unique,
  number_of_parked_cars int DEFAULT 0
);

CREATE TABLE Car(
  id int primary key not null auto_increment,
  name varchar(100) unique,
  person_id int,
  FOREIGN KEY(person_id) REFERENCES Person(id)
);

CREATE TABLE ParkingPlace(
  id int primary key not null auto_increment,
  name varchar(100),
  car_id int not null unique,
  FOREIGN KEY(car_id) REFERENCES Car(id)
);
/*
DELIMITER $$

CREATE TRIGGER update_number_of_parked_cars
  BEFORE INSERT
  ON ParkingPlace FOR EACH ROW

BEGIN
  UPDATE Person
  SET car_id = (
    SELECT COUNT(car_id) FROM ParkingPlace
    WHERE car_id = NEW.car_id
  )
  WHERE ParkingPlace.id = NEW.car_id;

END$$

DELIMITER ;
*/
INSERT INTO Person(name) Values("Misho");
INSERT INTO Person(name) Values("Misho sus index 2");
INSERT INTO Person(name) Values("Pesho");
INSERT INTO Person(name) Values("Gosho");
INSERT INTO Person(name) Values("Andon");
INSERT INTO Person(name) Values("Izmail");
INSERT INTO Person(name) Values("Kitaetza Hu Yo");
INSERT INTO Car(name, person_id) Values("CB1010HK", 1);
INSERT INTO Car(name, person_id) Values("CB1221SA", 2);
INSERT INTO Car(name, person_id) Values("CB1111WA", 3);
INSERT INTO Car(name, person_id) Values("CB7667KL", 4);
INSERT INTO Car(name, person_id) Values("CB3123JH", 5);
INSERT INTO Car(name, person_id) Values("CB2222HG", 6);
INSERT INTO Car(name, person_id) Values("CB1212DS", 7);
INSERT INTO Car(name, person_id) Values("CB1221GH", 1);
INSERT INTO Car(name, person_id) Values("CB1111SA", 2);
INSERT INTO Car(name, person_id) Values("CB9898AA", 3);
INSERT INTO ParkingPlace(name, car_id) Values("A1",1);
INSERT INTO ParkingPlace(name, car_id) Values("A2",2);
INSERT INTO ParkingPlace(name, car_id) Values("A3",3);
INSERT INTO ParkingPlace(name, car_id) Values("A4",4);
INSERT INTO ParkingPlace(name, car_id) Values("B1",5);
INSERT INTO ParkingPlace(name, car_id) Values("C16",6);
INSERT INTO ParkingPlace(name, car_id) Values("G3",7);
INSERT INTO ParkingPlace(name, car_id) Values("G4",8);

SELECT Person.name FROM ParkingPlace
LEFT JOIN Car ON  Car.id = ParkingPlace.car_id
LEFT JOIN Person on Person.id = Car.person_id;

SELECT Car.name, ParkingPlace.name FROM ParkingPlace
LEFT JOIN Car ON  Car.id = ParkingPlace.car_id
WHERE ParkingPlace.name LIKE "G%";
