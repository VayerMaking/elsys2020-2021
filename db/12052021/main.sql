drop database if exists instagram;
create database instagram;
use instagram;

create table Profile (
  id int not null primary key auto_increment,
  name varchar(100) unique
);

create table Post(
  id int not null primary key auto_increment,
  description varchar(100),
  type ENUM('post', 'video'),
  profile_id int not null,
  foreign key (profile_id) references Profile(id)
);

create table Komentar(
  id int not null primary key auto_increment,
  content varchar(500) not null,
  post_id int not null,
  foreign key (post_id) references Post(id),
  profile_id int not null,
  foreign key (profile_id) references Profile(id)
);

create table Llike(
  id int not null primary key auto_increment,
  post_id int not null,
  foreign key (post_id) references Post(id),
  profile_id int not null,
  foreign key (profile_id) references Profile(id)
);

insert into Profile(name) values ("misho");
insert into Profile(name) values ("nasko");
insert into Profile(name) values ("mimi");

insert into Post(description, type, profile_id) values ("not clickbait i give u money", "Video",1);
insert into Post(description, type, profile_id) values ("not clickbait i give u money 2" ,"Video", 1);
insert into Post(description, type, profile_id) values ("fun du ten","Video", 2);

insert into Komentar(content, post_id, profile_id) values ("purwi sum tuka", 1, 1);

select Profile.name, Post.description, Post.type From Profile
right join Post
on Profile.id = Post.profile_id;
-- where Post.type is not null;
select Profile.name as "Owner",
Post.description,
Komentar.content,
Profile.name as "komentiral"
from Post
right join Komentar
on Komentar.post_id = Post.id
left join Profile as komentiral
on Profile.id = komentiral.profile_id
left join Profile as owner
on Profile.id = owner.profile_id;

select owner.name, Post.description, Postliker.name, Llike.id
from Llike
left join Post
on Post.id = Llike.profile_id
left join Profile as owner
on owner.id = Post.profile_id
left join Profile as Postliker
on Postliker.id = Llike.profile_id;
