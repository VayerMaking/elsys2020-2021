DROP DATABASE IF EXISTS facebook;
CREATE DATABASE facebook;
USE facebook;

CREATE TABLE GGroup(
  id int primary key auto_increment not null,
  name varchar(100) unique
);

CREATE TABLE User(
  id int primary key auto_increment not null,
  name varchar(100) unique
);

CREATE TABLE User_GGroup(
  id int primary key auto_increment not null,
  group_id int,
  FOREIGN KEY(group_id) REFERENCES GGroup(id),
  user_id int,
  FOREIGN KEY(user_id) REFERENCES User(id)
);

CREATE TABLE Post(
  id int primary key auto_increment not null,
  name varchar(100) unique,
  content varchar(1000),
  group_id int,
  FOREIGN KEY(group_id) REFERENCES GGroup(id)
);

CREATE TABLE CComment(
  id int primary key auto_increment not null,
  content varchar(200),
  post_id int,
  FOREIGN KEY(post_id) REFERENCES Post(id),
  user_id int,
  FOREIGN KEY(user_id) REFERENCES User(id)
);

INSERT INTO GGroup(name) VALUES("pc master race");
INSERT INTO GGroup(name) VALUES("xbox(pc haters)");

INSERT INTO User(name) VALUES("Andreshko");
INSERT INTO User(name) VALUES("Dubai");
INSERT INTO User(name) VALUES("Danail");
INSERT INTO User(name) VALUES("Itzak");

INSERT INTO Post(name, content, group_id) VALUES("asdf", "asdasdasdasdasdasdasd", 1);
INSERT INTO Post(name, content, group_id) VALUES("as", "adsdasdasdad", 1);
INSERT INTO Post(name, content, group_id) VALUES("qwerty", "1111111111111", 2);
INSERT INTO Post(name, content, group_id) VALUES("gggggg", "bla lvlal vvla vlasl", 2);

INSERT INTO CComment(content, user_id, post_id) VALUES("ez", 1, 1);
INSERT INTO CComment(content, user_id, post_id) VALUES("kotka", 2, 1);
INSERT INTO CComment(content, user_id, post_id) VALUES("wow", 2, 2);
INSERT INTO CComment(content, user_id, post_id) VALUES("for real tho", 1, 2);
INSERT INTO CComment(content, user_id, post_id) VALUES("ya kiding", 3, 3);
INSERT INTO CComment(content, user_id, post_id) VALUES("asdf", 1, 4);
INSERT INTO CComment(content, user_id, post_id) VALUES("gangsta", 3, 4);

INSERT INTO User_GGroup(user_id, group_id) VALUES(1, 2);
INSERT INTO User_GGroup(user_id, group_id) VALUES(1, 1);
INSERT INTO User_GGroup(user_id, group_id) VALUES(2, 1);
INSERT INTO User_GGroup(user_id, group_id) VALUES(3, 2);

SELECT CComment.content as "Comment", User.name as "User", Post.name as "Post name", GGroup.name as "Group name"
FROM CComment
LEFT JOIN User ON CComment.user_id = User.id
LEFT JOIN Post ON CComment.post_id = Post.id
LEFT JOIN GGroup ON Post.group_id = GGroup.id;

SELECT * FROM User WHERE User.id NOT IN (SELECT CComment.user_id FROM CComment);

SELECT * FROM User WHERE User.id IN (SELECT User_GGroup.user_id FROM User_GGroup);
