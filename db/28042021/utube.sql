drop database if exists utube;
create database utube;
use utube;

create table Potrebitel (
  id int not null primary key auto_increment,
  name varchar(100) unique
);

create table Kanal(
  id int not null primary key auto_increment,
  name varchar(100) unique
);

create table PotrebitelKanal(
  id int not null primary key auto_increment,
  potrebitel_id int not null,
  FOREIGN KEY (potrebitel_id) references Potrebitel(id),
  kanal_id int not null,
  foreign key (kanal_id) references Kanal(id),
  constraint UniqueKanalPotrebitel Unique(kanal_id, potrebitel_id)
);

create table Video(
  id int not null primary key auto_increment,
  title varchar(100),
  kanal_id int not null,
  foreign key (kanal_id) references Kanal(id)
);

create table Komentar(
  id int not null primary key auto_increment,
  content varchar(500) not null,
  video_id int not null,
  foreign key (video_id) references Video(id),
  potrebitel_id int not null,
  foreign key (potrebitel_id) references Potrebitel(id)
);

insert into Potrebitel(name) values ("misho");
insert into Potrebitel(name) values ("nasko");
insert into Potrebitel(name) values ("mimi");

insert into Kanal(name) values ("mishto & mimi adventures");
insert into Kanal(name) values ("make up tutorialos");
insert into Kanal(name) values ("vlog squad");

insert into PotrebitelKanal(potrebitel_id, kanal_id) values (1, 1);
insert into PotrebitelKanal(potrebitel_id, kanal_id) values (3, 1);
insert into PotrebitelKanal(potrebitel_id, kanal_id) values (2, 2);
insert into PotrebitelKanal(potrebitel_id, kanal_id) values (1, 3);
insert into PotrebitelKanal(potrebitel_id, kanal_id) values (2, 3);
insert into PotrebitelKanal(potrebitel_id, kanal_id) values (3, 3);

insert into Video(title, kanal_id) values ("not clickbait i give u money", 1);
insert into Video(title, kanal_id) values ("not clickbait i give u money 2", 1);
insert into Video(title, kanal_id) values ("fun du ten", 2);
insert into Video(title, kanal_id) values ("nails", 2);
insert into Video(title, kanal_id) values ("vlog[0]", 3);
insert into Video(title, kanal_id) values ("vlog[1]", 3);

insert into Komentar(content, video_id, potrebitel_id) values ("purwi sum tuka", 1, 1);

select Potrebitel.name, Kanal.name from PotrebitelKanal
left join Potrebitel
on PotrebitelKanal.potrebitel_id = Potrebitel.id
left join Kanal
on PotrebitelKanal.kanal_id = Kanal.id;

select Kanal.name, Video.title from Kanal
left join Video
on Kanal.id = Video.kanal_id;

select Kanal.name, Potrebitel.name, Video.title, Komentar.content from Komentar
left join Video
on Video.id = Komentar.video_id
left join Potrebitel
on Komentar.potrebitel_id = Potrebitel.id
left join Kanal
on Video.kanal_id = Kanal.id;

select komentirasht.name, Komentar.content, pritejavasht.name from Potrebitel as komentirasht
left join Komentar
on Komentar.potrebitel_id = komentirasht.id
left join Video
on Komentar.video_id = Video.id
left join Kanal
on Video.kanal_id = Kanal.id
left join PotrebitelKanal
on PotrebitelKanal.kanal_id = Kanal.id
left join Potrebitel as pritejavasht
on PotrebitelKanal.potrebitel_id = pritejavasht.id;

select count(*) from Komentar
left join Potrebitel
on Komentar.potrebitel_id = Potrebitel.id
where Potrebitel.name like "misho";
