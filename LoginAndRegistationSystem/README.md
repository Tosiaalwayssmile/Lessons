Program connecting to SQL Server database with such features as:
1) signing in
2) signing up
3) changing password
4) deleting the account
5) signing off.
It allows selecting, inserting, updating and deleting data in the database.

For this program to work you need to:
1) Install sql server
2) Install Visual Studio (preferably)
3) Create database using this script:
    USE master;
    GO
    IF NOT EXISTS (SELECT * FROM sys.databases WHERE name = 'usersDatabase')
    BEGIN
    CREATE DATABASE usersDatabase;
    END;
    GO
    use usersDatabase; 
    CREATE TABLE Users (
  	UserID int IDENTITY(1,1) PRIMARY KEY,
    LastName varchar(255),
    FirstName varchar(255),
    Password varchar(255)
    );
   INSERT INTO Users (LastName, FirstName, Age, Password) VALUES ('ExampleLastName', 'ExampleFirstName', Age, 'ExamplePassword');
4) Enable TCP/IP Connection. See this article for reference: https://knowhow.visual-paradigm.com/hibernate/solving-sql-server-connection-problem/
5) Allow Remote Connection
6) Make sure Hostname and Port are correct. 52nd line in code in SQLHandle.cpp where possbile modifications may be needed: 
switch (SQLDriverConnectW(sqlConnHandle, NULL, (SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=usersDatabase;Trusted=true;",SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
7) In project properties change the default 'Character Set' from 'Use Unicode Character Set to 'Use Multi-Byte Character Set'. 
In Polish: We właściwościach projektu zmień Właściwości konfiguracji -> Zaawansowane -> Zestaw znaków -> zmień 'Użyj kodowania Unicode' na 'Używaj wielobajtowego zestawu znaków'.    
   
