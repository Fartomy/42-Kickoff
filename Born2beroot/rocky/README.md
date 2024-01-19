# Rocky

This installation is based on **Rocky Linux** and **bonus part** is included.

## 1️⃣ Part 1 - Install Rocky Linux

First download **VirtualBox** and download **Rocky's .iso** file. Here are the links:
- [VirtualBox](https://www.virtualbox.org/)
- [Rocky Linux](https://rockylinux.org/)
...


🏁**And finally Part 1 ends here..**🏁
## 2️⃣ Part 2 - Downloads and Adjustments and and Configurations

After entering your disk password, you will see this screen. Probably this is the login screen. :d

images1
images2

You can see the partitions and encrypted partitions of your disk by running this command:

`lsblk`

Before proceeding with the downloads and configurations, it is useful to know these:

- Be root:

`su`

- Scan if there is an updated package:

```
dnf -y update
```

🛎️ Change the hostname:

To change the hostname, let's enter the file (you must be root):

```
vi /etc/hostname
```
Change your hostname as it needs to be changed.

Restart the computer after saving and exiting:

`reboot`

🧮 User Commands

Apart from these, the command to see the users in your system:

`getent passwd`

Commands for adding and deleting users:

`adduser <user_name>` - `userdel <user_name>`

To assign a password to the created user:

`passwd <user_name>`

🍇 Group Commands

The command to see the groups in your system:

`getent group` or `getent group <group_name>` -> **Users under a group**

Commands for adding and deleting groups:

`groupadd <group_name>` - `groupdel <group_name>`


🤝 Commands of groups used with users

First command to see which group a user is in:

`groups <user_name>`

Command to add and remove a user from a group:

`usermod -aG <group_name> <user_name>` - `gpasswd --delete <user_name> <group_name>`

### 🛠️ Installing packages and configuring files

#### 🧰 For SSH

The **SSH server** package is probably already downloaded. If not, run the command below:

- Install SSH server package:

```
dnf -y install openssh-server
```

SSH activity query command and ssh start commands:

`systemctl status sshd` - `systemctl start sshd` - `systemctl enable sshd`

##### 🧬 SSH Port Change

You should go to this directory:

```
vi /etc/ssh/sshd_config
```

You should change these settings:
- #Port 22 -> Port 4242
- #PermitRootLogin prohibit-password -> PermitRootLogin no
- And yes, remove the '#' as well, they will comment out what you wrote. :)
- Hey! by the way just remove the '#' signs for the 2 settings I mentioned above. :d

image1
image2

Okay, after making these settings, restart with the command:

```
systemctl sshd restart
```

You will probably encounter an error like this:

image1

To solution:

```
dnf install -y policycoreutils-python-utils
```

To overcome this problem, we need to make some configurations in Selinux's security policy settings. :

```
semanage port -a -t ssh_port_t -p tcp 4242
```

Check the port context for SSH:

```
semanage port -l | grep ssh
```

Restart SSHD service:

```
systemctl restart sshd
```

Then, we need to make another small setting for the port setting we want on the firewalld side:

```
firewall-cmd --permanent --zone=public --add-port=4242/tcp
```

Reload Firewalld:

```
firewall-cmd --reload
```

List firewalld ports:

```
firewall-cmd --list-port
```

List firewalld service:

```
firewall-cmd --list-service
```

List firewalld all:

```
firewall-cmd --list-all

```

To check the listening ports:

```
ss -tnlp | grep ssh
```

Okay, now that we have checked a lot of things and made ourselves sure about this, the next step will be port forwarding :d

Back to your virtualbox and press 'settings' at the top, then 'network', then there will be an 'Advanced' pane at the bottom, click there and press 'Port Forwarding'. You will see a button with a green '+' sign on the right, yes press it and something like a table will appear. Do as in the picture in the 'Host port' and 'Guess Port' sections. I'm already adding a picture, I don't know why I felt the need to explain. Anyway, press ok ok and it's over.

image1
image2


Now we look like we are ready to connect via SSH via your host machine.

```
ssh ruser@localhost -p 4242
```

[Optional Problem]

```
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@    WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED!     @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
IT IS POSSIBLE THAT SOMEONE IS DOING SOMETHING NASTY!
Someone could be eavesdropping on you right now (man-in-the-middle attack)!
It is also possible that a host key has just been changed.
The fingerprint for the ***** key sent by the remote host is
SHA256:*****************/********/****.
Please contact your system administrator.
Add correct host key in /home/your_username/.ssh/known_hosts to get rid of this message.
Offending ECDSA key in /home/your_username/.ssh/known_hosts:3
  remove with:
  ssh-keygen -f "/home/your_username/.ssh/known_hosts" -R "[localhost]:4242"
Host key for [localhost]:4242 has changed and you have requested strict checking.
Host key verification failed.
```
If you encounter such a situation, what you need to do is stated in the message.

🚩 Yes, SSH that was it.. 🚩

#### :godmode: For Sudo

Configuring **sudo** according to very very strict rules

If sudo is not available on the system::

```
dnf install -y sudo
```

If the **sudo** group does not exist in the system, create it:

```
groupadd sudo
```

Include the user who needs to be added to this group:

```
usermod -aG sudo <user_name>
```

OK, we did a lot, now let's move on to the config settings: :d

Let's enter the configuration file with this command:

`visudo`

A screen like this should come:

image1


Add some strict rules here:

```
Defaults     passwd_tries=3 -> 3 wrong entries
Defaults     badpass_message="Wrong Password!!!" -> wrong password message
Defaults     requiretty -> terminal requirement for sudo command
Defaults     logfile="/var/log/sudo/sudo.log" -> logs of every sudo command entered
Defaults     log_input, log_output -> I/O of sudo commands
Defaults     iolog_dir="/var/log/sudo/" -> path of inputs and outputs
```

The last one should look like this:

image2

[Intriguing Ancient Infos]

{requiretty}

It prevents us from running commands and scripts remotely without fully connecting to a remote system via SSH.

Try this command on your host machine:

```
ssh your_username@localhost -p 4242 'echo 'your_pass' | sudo -S ls -al'
```

(Or you can create a script file and paste that command and run the script file. It will not be working because require tty)

(We can send command with ssh but it is must be between quotes (''). And for sudo password we must use '-S' option and we can send that with "echo")

{secure_path}

What are Environment Variables (Environment Variables)?
Environment variables are global variables that the operating system and applications use to store and share configuration information. These variables contain various settings and preferences that are valid throughout the system or session.

One of the Most Common Environment Variables is: PATH
The PATH environment variable contains a list of directories where the operating system searches for commands. For example, when you type the ls command on the command line, the system searches for the ls command in directories defined in PATH.
A PATH is a list Decoupled by the character : between various directory paths. For example: /usr/bin:/bin:/usr/sbin:/sbin
sudo and secure_path
sudo is a tool that allows you to run a command with superuser (root) rights. when sudo is used, for security reasons, the system uses the secure_path setting in the sudoers file instead of using the PATH environment variable.

secure_path Function:
when a command is executed with sudo, the paths defined in secure_path are used as secure directories to search for the command.
This prevents users or scripts from executing commands in unsafe directories with sudo.
Example Scenario and Description
Let's say that your system has a directory named /custom/bin, and this directory is not defined in secure_path. Let's assume that there is a command named testcommand in this directory.

Running a Command as a Normal User:

When you run the /custom/bin/testcommand command as a user, the system uses the PATH environment variable and the command runs.
Running a Command with sudo:

when you run the sudo/custom/bin/testcommand command, sudo uses secure_path.
If /custom/bin is not defined in secure_path, sudo will not be able to find this command and will not be able to execute it. This indicates that sudo uses only the paths defined in secure_path.
Test
To test this situation:

create /custom/bin/testcommand (or another directory/command).
Add this directory to the PATH: export PATH=$PATH:/custom/bin
Run the command as a normal user: /custom/bin/testcommand
run with sudo: sudo/custom/bin/testcommand
If the sudo command gives a "command not found" error, this indicates that secure_path is working.


To confirm these, you can exit **root** and try what can be done with the **sudo** command

🚩 Yes, Sudo that was it.. 🚩


#### ⛓️ Password Policy

First, configure the password change frequency:

```
nano /etc/login.defs
```

You find it "**Password aging control**":

image

Then do it like this:

```
PASS_MAX_DAYS   30
PASS_MIN_DAYS   2
PASS_WARN_AGE   7
```

**⚠️Yes, that's all, but this setting is valid for root and users after you (usr). To change your user and root's, do this⚠️**

First, let me prove it to you:

`chage -l root` and `chage -l <user_name>` -> I think that's a enough proof :d

To change:

`chage root` and `chage <user_name>`

image

You know what to do..

Now let's add our password creation rules

Follow this path:
```
vi /etc/security/pwquality.conf
```

You will encounter something like this:

image1

Here's what you need to change:

```
difok = 7
minlen = 10
dcredit= -1
ucredit= -1
enforce_for_root
enforcing= 1
maxrepeat= 3
usercheck = 1
dictcheck = 1
```

I'm not going to write explanations, it's already written :()

**⚠️Yes, that's all, but after you've done these, you still need to change the passwords for root, your user, and all other users if you have created them⚠️**

`passwd root` and `passwd <user_name>`

🏁**And finally Part 2 ends here..**🏁


## 3️⃣ Part 3 - Monitoring.sh and Crontab Configurations

### 🗒️ Monitoring.sh

If you want to examine it, I shared the **monitoring.sh** file above.

[monitoring.sh link]

### ⏰ Crontab (cron)

Type this command:

```
crontab -e
```

and write that:

```
*/10 * * * * bash /your/monitoring.sh_path
```
🏁 And finally Part 3 ends here.. 🏁

## Part 4 - Last Checks

Make sure the outputs are as expected:

```
head -n 2 /etc/os-release
```

```
sestatus
```

```
ss -tunlp
```

```
firewall-cmd --list-service
```

```
firewall-cmd --list-port
```

```
firewall-cmd --state
```

For example, I did not get the expected output from the **"ss -tunlp"** command. A service named **"chronyd"** was listening on a certain port, now let's close it.

image

To solution:

`systemctl stop chronyd` then `systemctl disable chronyd`

image

Finally, there are many services running on firewalld. 

image

To remove them:

`firewall-cmd --permanent --remove-service=cockpit` - `firewall-cmd --permanent --remove-service=dhcpv6-client` - `firewall-cmd --reload`

image

🏁 And finally Part 4 ends here.. 🏁

## Part Bonus - Wordpress setup and Choice of Your Service

### For Lighttpd

The simplest way to install Lighttpd is by adding the EPEL repository and updating the software list using the following commands:

```
dnf -y install epel-release && dnf -y update && dnf -y install lighttpd
```

After installing Lighttpd, you need to start, enable the service to automatically start at boot time, and make sure to verify the status using the following commands:

```
# systemctl start lighttpd
# systemctl enable lighttpd
# systemctl status lighttpd
```

After activating the lighttpd service, there will be some errors in the "status" output. To solve these:

image

Enable "httpd_setrlimit" in selinux policy settings:
```
setsebool -P httpd_setrlimit on
```

Then go to **lighttpd** config file for other problem:

```
vi /etc/lighttpd/lighttpd.conf
```

Find `server.use-ipv6 = "enable"` section and change that line to
`server.use-ipv6 = "disable"`

image
image

Restart the **lighttpd** service:

```
systemctl restart lighttpd
```

Make sure to open HTTP traffic on your firewall:

```
# firewall-cmd --permanent --zone=public --add-service=http
# firewall-cmd --reload
```

Add port in the VirtualBox's port forwarding settings:

image

Now open your browser and navigate to the following URL to confirm that your Lighttpd web server is running:

```
http://localhost:8080
```

The default configuration file for Lighttpd is /etc/lighttpd/lighttpd.conf and the document root directory is /var/www/lighttpd/.


### For MariaDB

Install MariaDB:

```
dnf -y install mariadb mariadb-server
```

After installing MariaDB, you need to start, enable and verify the status as shown:

```
# systemctl start mariadb
# systemctl enable mariadb
# systemctl status mariadb
```

Once MariaDB is running, you need to secure installation by issuing the following security script command:

```
mysql_secure_installation
```

The script will ask you to create a new root password, remove anonymous users, disable root login remotely. remove test database, and reload the privilege table:

image

Once you secured MariaDB installation, try to connect to the MariaDB shell from the terminal using the new password:

```
# mysql -u root -p
MariaDB [(none)]> show databases;
```

image

### For PHP

To install PHP with the PHP-FPM and FastCGI support, you need to install PHP along with the needed modules as shown:

```
dnf -y install php php-mysqlnd php-pdo php-gd php-mbstring php-fpm lighttpd-fastcgi
```

Next, open the php-fpm configuration file:

```
vi /etc/php-fpm.d/www.conf
```

Set the user and group to **lighttpd** as shown:
```
; Unix user/group of processes
; Note: The user is mandatory. If the group is not set, the default user's group
;       will be used.
; RPM: apache Choosed to be able to access some dir as httpd
user = lighttpd
; RPM: Keep a group allowed to write in log dir.
group = lighttpd
```

Also, by default php-fpm uses listen = /run/php-fpm/www.sock socket, you need to make this line to listen = 127.0.0.1:9000 as TCP connection.

```
;listen = /run/php-fpm/www.sock
listen = 127.0.0.1:9000 
```

Before:

image

After:

image

After making changes, you need to start, enable and verify the status of php-fpm:

```
# systemctl start php-fpm.service
# systemctl enable php-fpm.service
# systemctl status php-fpm.service
```

#### Enabling PHP and PHP-FPM with FastCGI in Lighttpd

To enable FastCGI support in PHP, you need to make the configuration changes in three files as follows.

Open first file `/etc/php.ini`

```
vi /etc/php.ini
```

Un-comment the following line that says a line `cgi.fix_pathinfo=1`

Before:
image

After:
image

Then open second file called `/etc/lighttpd/modules.conf`

```
vi /etc/lighttpd/modules.conf
```

Un-comment the following line that says include `include conf_dir + "/conf.d/fastcgi.conf"`

Before:
image

After:
image

Next, open third file called `/etc/lighttpd/conf.d/fastcgi.conf`

```
vi /etc/lighttpd/conf.d/fastcgi.conf
```

Now add the following container at the bottom of the file and save it:

```
fastcgi.server += ( ".php" =>
        ((
                "host" => "127.0.0.1",
                "port" => "9000",
                "broken-scriptfilename" => "enable"
        ))
)
```

Before:

image

After:

image

Restart the Lighttpd service to reflect changes and enable PHP support:

```
systemctl restart lighttpd
```

After making all the above configuration changes, you need to test the FastCGI support in PHP by creating a phpinfo.php file under /var/www/lighttpd/ directory:


```
vi /var/www/lighttpd/phpinfo.php
```

Add the following lines to it:

```
<?php
phpinfo();
?>
```

Open your browser and navigate to the following URL to test the FastCGI support in PHP:

```
http://localhost:8080/phpinfo.php
```

If I'm not mistaken, you see the `503 service unavailable` error when you try to access the `phpinfo.php` page:

Again, you will need to consult Selinux policies:

```
setsebool -P httpd_can_network_connect on
```

[mini info]:
For a full list of these policies:

```
getsebool -a
```

### For Wordpress

First of all, you should install these packages:

```
dnf install -y wget unzip
```

Download WordPress packages:

```
wget https://wordpress.org/latest.zip
```

Extract files:

```
unzip latest.zip
```

Let's adjust some permission settings to avoid problems with reading and writing:

```
# find wordpress/ -type d -exec chmod 755 {} \;
# find wordpress/ -type f -exec chmod 644 {} \;
```

Enter wordpress dir and copy the files to `/var/www/lighttpd/`:

```
cp -r * /var/www/lighttpd/
```

Let's create a database and user for WordPress in MariaDB:

```
mysql -u root -p
```

Execute the following commands in MariaDB:
```
create database example_db default character set utf8 collate utf8_unicode_ci;
```

```
create user 'example_user'@'localhost' identified by 'example_pw';
```

```
grant all privileges on example_db.* TO 'example_user'@'localhost';
```

```
flush privileges;
```

Finally, **exit** from MariaDB.

Now we can go to the WordPress installation page:

```
http://localhost:8080/index.php
```

image

image

image

We are having a problem with write permission to the `wp-config.php` file on the system. 

to Solution:


```
chcon -t httpd_sys_rw_content_t /var/www/lighttpd/
```

Try again.

image

image

image

image

image

🏁 And finally Part Bonus ends here.. 🏁

## Part 5 - Submission and Peer-evaluation

Now that everything is finished, it's time to get your disc signature:

First of all, you should go into the file we have installed in '/goinfre' and find your virtual machine. I'm assuming you went there as I wouldn't know where this is.

Type this:
```
shasum <your_virtual_machine>.vdi.
```

It might take a while..

When your disk signature comes, you will send it to the 'signature.txt' file and get push. That's all. If you've come this far, 🥳CONGRATULATIONS!!!🥳

🏁**And finally Episode 5 ends here..**🏁

## Extras and Resources

1. [SSH Port Policies and Configures Setup](https://serverfault.com/questions/538037/sshd-service-fails-to-start)
2. [Linux Groups](https://www.redhat.com/sysadmin/linux-groups)
3. [PASSWORD POLICY (PAM CONFIG)](https://ostechnix.com/how-to-set-password-policies-in-linux/)
4. [Bonus Lighttpd Config](https://www.tecmint.com/install-lighttpd-rockylinux-almalinux/)
5. [Install WordPress in Virtual Machine (Video)](https://www.youtube.com/watch?v=PsMhopODLTY)
6. [Install WordPress in Locally (Video)](https://www.youtube.com/watch?v=PhNxEZcxXV0)

🏁**And finally README.md ends here..**🏁

GIF image

