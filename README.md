# File Downloader
 Downloads files from a ftp server with encrypted request
 
 Put the PHP Folder on ur FTP server
 and use the code in C++ Folder to download the files
 replace the url part in the C++ code to ur own url which directs to the folder on ur FTP server with the php code in it.
 
 Advantages using this over normal file downloads are that if someone tampers with ur program no data is exposed that could reveal critical data.
 Grabbing methods like HTTP Debuggers dont reveal a certain url to a file and the data in the reqeust header is encrypted
 
 I know the encryption is very weak just replace it with some real AES encryption
