drop database if exists gallery;
create database gallery;
use gallery;

create table Person(
	id int primary key not null auto_increment,
  	name varchar(100) not null unique,
  	age int not null,
  	CHECK (age>0)
);

create table Room(
	id int primary key not null auto_increment,
	name varchar(100) unique not null
);

create table Art(
	id int primary key not null auto_increment,
	name varchar(100) not null unique,
  	price float not null,
  	room_id int not null,
	foreign key (room_id) references Room(id),
  	CHECK (price > 0)
);

create table PersonRoom(
	id int primary key not null auto_increment,
  	date_of_entering timestamp not null,
	person_id int not null,
	foreign key (person_id) references Person(id),
  	room_id int not null,
  	foreign key (room_id) references Room(id)
);

INSERT INTO Person(name, age) VALUES("Misho", 20);
INSERT INTO Person(name, age) VALUES("Mimi", 21);
INSERT INTO Person(name, age) VALUES("Nasko", 24);

INSERT INTO Room(name) VALUES("205");
INSERT INTO Room(name) VALUES("200A");
INSERT INTO Room(name) VALUES("123");

INSERT INTO Art(name, price, room_id) VALUES("Beeple", 200, 3);
INSERT INTO Art(name, price, room_id) VALUES("Vapsky", 20, 1);
INSERT INTO Art(name, price, room_id) VALUES("Mona Lisa", 2, 2);

INSERT INTO PersonRoom(date_of_entering, person_id, room_id) VALUES("2020-01-22", 1, 1);
INSERT INTO PersonRoom(date_of_entering, person_id, room_id) VALUES("2020-01-22", 1, 1);
INSERT INTO PersonRoom(date_of_entering, person_id, room_id) VALUES("2020-01-21", 1, 2);
INSERT INTO PersonRoom(date_of_entering, person_id, room_id) VALUES("2020-01-24", 1, 2);
INSERT INTO PersonRoom(date_of_entering, person_id, room_id) VALUES("2020-01-25", 1, 3);
INSERT INTO PersonRoom(date_of_entering, person_id, room_id) VALUES("2020-01-31", 1, 3);

INSERT INTO PersonRoom(date_of_entering, person_id, room_id) VALUES("2020-01-22", 3, 3);
INSERT INTO PersonRoom(date_of_entering, person_id, room_id) VALUES("2020-01-22", 3, 3);

select Room.name from PersonRoom
left join Room
on Room.id = room_id
group by room_id
order by count(room_id) desc
limit 1;

select Person.name from PersonRoom
left join Person
on Person.id = person_id
left join Room
on Room.id = room_id
where Room.name like '2%'
group by Person.name;

select Person.name from PersonRoom
right join Person
on Person.id = person_id
where person_id is null
group by Person.name;

select Person.name, count(PersonRoom.id) from PersonRoom
left join Person
on Person.id = person_id
left join Room
on Room.id = room_id
group by Person.name;

select Person.name, Art.name, Art.price from PersonRoom
left join Person
on Person.id = person_id
left join Room
on Room.id = room_id
left join Art
on Room.id = Art.room_id
order by Art.price desc;

