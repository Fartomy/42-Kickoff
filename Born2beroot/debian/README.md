<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/debian_gif.gif" align="right" height="400">

# Debian

This installation is based on **Debian** and **bonus part** is included.

## 🧭 Road Map

1.  [Episode 1 (Install Debian)](https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/README.md#one-episode-1-install-debian)

2. [Episode 2 (Downloads and Adjustments and and Configurations)](https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/README.md#two-episode-2-downloads-and-adjustments-and-and-configurations)
   - [For SSH](https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/README.md#-for-ssh)
   - [For UFW](https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/README.md#%EF%B8%8F-for-ufw)
   - [For Sudo](https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/README.md#godmode-for-sudo)
   - [Password Policy](https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/README.md#%EF%B8%8F-password-policy)

3. [Episode 3 (Monitoring.sh and Crontab Configurations)](https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/README.md#3%EF%B8%8F%E2%83%A3-episode-3-monitoringsh-and-crontab-configurations)

4. [Episode 4 (Submission and Peer-evaluation)](https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/README.md#four-episode-4-submission-and-peer-evaluation)

5. [Extras and Resources](https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/README.md#5%EF%B8%8F%E2%83%A3-extras-and-resources)
  
## :one: Part 1 - Install Debian

First download VirtualBox and download Debian's .iso file. Here are the links:

- [VirtualBox](https://www.virtualbox.org/)

- [Debian](https://www.debian.org/)

After installing open virtualbox:

Press the above will also be the new key!

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/1.png" align="center" height="325">

Next next next.. and 'Machine Folder' your machine folder path will be '/goinfre' but but be careful the hard disk file type will be vdi.

And then choose **'.iso'** Debian file. Click on the virtual machine you have created and click **'settings'** above. and from there click on **'Storage'**, click on **'Empty'** and press the **CD** sign next to the **'Optical Drive'** option in the right window. From there, click on **'Choose Disk File'** and select your downloaded debian **'.iso' file.

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/2.png" align="center" height="325">

Setup video:

[Debian Setup Video](https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/setup_debian.mp4)

**🏁And finally Episode 1 ends here..🏁**

## :two: Part 2 - Downloads and Adjustments and and Configurations

You will see this screen, probably this is the login screen

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/31.png" align="center" height="300">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/32.png" align="center" height="300">

You can see the partitions and encrypted partitions of your disk by running this command:

```
lsblk
```

Before proceeding with the downloads and configurations, it is useful to know these:

- Be root:

```
su -
```

- Scan if there is an updated package:

```
apt update
```

- If there is a package that needs to be updated, update it:

```
apt upgrade
```

### 🛎️ Change the Hostname

Command to see hostname:

```
hostname
```

To change the hostname, let's enter the following file with nano **(you must be root)**:

```
nano /etc/hostname
```

You will probably see the hostname, yes change it and save:

`CTRL + O then ENTER and then CTRL + X to save and exit in nano`

Restart the computer after saving and exiting:

```
reboot
```

If you want to revert repeat these steps :d

### 🧮 User Commands

Apart from these, the command to see the users in your virtual machine:

```
getent passwd
```

Commands for adding and deleting users:

```
# adduser <user_name>```
# deluser <username>
```

### 🍇 Group Commands

The command to see the groups in your virtual machine:

```
# getent group```
# getent group <group_name> -> Users under a group
```

Commands for adding and deleting groups:

```
# groupadd <group_name>
# groupdel <group_name>
```

As an example, let's add the `user42` group:

```
groupadd user42
```

### 🤝 Commands of groups used with users

First command to see which group a user is in:

```
groups <user_name>
```

Command to add and remove a user from a group:

```
# usermod -aG <group_name> <user_name>
# gpasswd --delete <user_name> <group_name>
```

Now let's add the user under the `user42` group:

```
usermod -aG user42 <user_name>
```

## 🛠️ Installing packages and configuring files

### 🧰 For SSH

Install SSH:

```
apt install openssh-server
```

SSH activity query command and ssh start commands:

```
# systemctl start sshd
# systemctl enable sshd
# systemctl status ssh
```

#### :dna: SSH Port Change

You should go to this directory:

```
nano /etc/ssh/sshd_config
```
You should change these settings:

```
- #Port 22 -> Port 4242
- #PermitRootLogin prohibit-password -> PermitRootLogin no
- And yes, remove the '#' as well, they will comment out what you wrote. :)
- Hey! by the way just remove the '#' signs for the 2 settings I mentioned above. :d
```

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/33.png" height="300">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/34.png" align="center" height="300">

Okay, after making these settings, restart with the command:

```
systemctl restart sshd
```

Then come to your virtualbox and press **'settings'** at the top, then **'network'**, 
then there will be an **'Advanced'** pane at the bottom, click there and press **'Port Forwarding'**. 
You will see a button with a green **'+'** sign on the right, yes press it and something like a 
table will appear. Do as in the picture in the **'Host port'** and **'Guess Port'** sections. 
I'm already adding a picture, I don't know why I felt the need to explain. Anyway, press ok ok and it's over.

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/35.png" align="center" height="300">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/36.png" align="center" height="300">

After doing these restart your virtual machine:

```
reboot
```

After these settings, you can now connect to the virtual machine from the your host:

```
ssh your_username@localhost -p 4242
```

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/37.png" align="center" height="300">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/38.png" align="center" height="300">

And you can access the virtual machine from the terminal of the host by entering the password of the user in your virtual machine.

**🚩Yes, SSH that was it..🚩**

### 🛡️ For UFW

Install UFW:

```
apt install ufw
```

#### :eye_speech_bubble: Some UFW related commands

Deny all requests to us:

```
ufw default deny incoming
```

Allow all outbound requests:

```
ufw default allow outgoing
```

Enable ufw on system startup (Reboot your virtual machine after doing this):

```
ufw enable
```

Check out UFW's status:

```
# ufw status
# ufw status numbered -> numbered the rules
```

Allow incoming requests to port 4242 or deny this port:

```
# ufw allow 4242
# ufw deny 4242
```

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/39.png" align="center" height="300">

to delete a rule:

```
# ufw delete allow 4242 -> this command deletes 'allow' rules 4242
# ufw delete deny 4242  -> deletes 'deny' rules 4242 <br/>
# ufw delete 1 -> deletes rule 1
```

**🚩Yes, UFW that was it..🚩**

### :godmode: For Sudo

Configuring `sudo` according to very very strict rules

Install Sudo:

```
apt install sudo
```

Add your user under the `sudo` group before proceeding to the config settings:

```
usermod -aG sudo <user_name>
```

```
visudo -> Let's enter the configuration file with this command
```

A screen like this should come:

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/40.png" align="center" height="300">

Add some strict rules here:
 
 ```
 Defaults     passwd_tries=3 -> 3 wrong entries
 Defaults     badpass_message="Wrong Password!!!" -> wrong password message
 Defaults     requiretty -> terminal requirement for sudo command
 Defaults     logfile="/var/log/sudo/sudo.log" -> logs of every sudo command entered
 Defaults     log_input, log_output -> I/O of sudo commands
 Defaults     iolog_dir="/var/log/sudo/" -> path of inputs and outputs
```

[mini info]

{secure_path}
```
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
```

The last one should look like this:

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/41.png" align="center" height="300">

To confirm these, you can exit _root_ and try what can be done with the `sudo` command.

**🚩Yes, `sudo` that was it..🚩**

### ⛓️ Password Policy

First, configure the password change frequency:

```
nano /etc/login.defs
```
You find it _Password aging control_:

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/42.png" align="center" height="300">

Then do it like this:

```
PASS_MAX_DAYS   30
PASS_MIN_DAYS   2
PASS_WARN_AGE   7
```

_**⚠️Yes, that's all, but this setting is valid for root and users after you (usr). To change your user and root's, do this⚠️**_

First, let me prove it to you:

```
# chage -l root
# chage -l <user_name> -> I think that's a enough proof :()
```

To change:

```
# chage root
# chage <user_name>
```

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/43.png" align="center" height="300">

You know what to do..

Now let's add our password creation rules

Install it:

```
apt install libpam-pwquality
```

Then follow this path:

```
nano /etc/security/pwquality.conf
```
You will encounter something like this:

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/44.png" align="center" height="300">

Here's what you need to change:

```
difok = 7
minlen = 10
dcredit= -1
ucredit= -1
lcredit=-1
enforce_for_root
enforcing= 1
maxrepeat= 3
usercheck = 1
dictcheck = 1
```

I'm not going to write explanations, it's already written :()

_**⚠️Yes, that's all, but after you've done these, you still need to change the passwords for root, your user, and all other users if you have created them⚠️**_

How does?

```
# passwd root
# passwd <user_name>
```

**🏁And finally Episode 2 ends here..🏁**

## 3️⃣ Part 3 - Monitoring.sh and Crontab Configurations

### 🗒️ Monitoring.sh

If you want to examine it, I shared the _monitoring.sh_ file above.

[Monitoring.sh](https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/monitoring.sh)

### ⏰ Crontab (cron)

Type this command:

```
crontab -e
```

[mini info]

```
The crontab -e command allows you to edit a crontab file belonging to the user who performed the operation.

For example, when user user1 adds a crontab task using the crontab -e command, that task is added to the crontab file belonging to user user1. 
Other users cannot see or edit this file.

A special folder in the system context, such as `/var/spool/cron/crontabs` or `/var/spool/cron`, is often used to access the user's crontab file. 
However, these files should not be edited directly; `crontab -e` should be used instead because this command preserves the structure of the files and provides the user with a safe editing environment.
```

Anyway, write at the bottom:

```
*/10 * * * * bash /your/monitoring.sh_path
```

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/45.png" align="center" height="300">

**🏁And finally Episode 3 ends here..🏁**

## :four: Part 4 - Submission and Peer-evaluation

Now that everything is finished, it's time to get your disc signature:

First of all, you should go into the file we have installed in _/goinfre_ and find your virtual machine.
I'm assuming you went there as I wouldn't know where this is.

Type this:

```
shasum <your_virtual_machine>.vdi
```

When your disk signature comes, you will send it to the 'signature.txt' file and get push. That's all. If you've come this far, 🥳CONGRATULATIONS!!!🥳

**🏁**And finally Episode 4 ends here..🏁**

## 5️⃣ Extras and Resources

### ➕ Extras

1-) You can connect to your friend's virtual machine using SSH.

2-) With _netcat_, you can chat with your friends via terminal.

Materials:

- IPv4adress
```
# apt install net-tools
# ifconfig
```

- Port

```
netstat -anvp tcp | awk 'NR<3 || /LISTEN/' -> find open port
```

🥂 How to use NetCat

First of all, type the open port of your friend's PC into the terminal:

```
nc -l <port -> and ENTER. and your friend wait. Then go to your own computer
```

After that, type your friend's _IPv4_ address and port number and press _ENTER_.
Let the messaging begin!

```
nc <IPv4_adress> <port>
```

☣️ If you forget your Debian user and root passwords

[Debian Password Reset](https://www.youtube.com/watch?v=3Hrm3_CFKic)

### :brain: Resources

1. [Aptitude vs apt](https://dijitalders.net/icerik/22/2369/apt_get_ve_aptitude.html)
2. [Sudo](https://medium.com/@gokhansengun/sudo-nas%C4%B1l-kullan%C4%B1l%C4%B1r-ve-incelikleri-nelerdir-52db87d74ba)
3. [SElinux](https://www.redhat.com/en/topics/linux/what-is-selinux)
4. [AppArmor](https://apparmor.net/)
5. [SSH](https://www.hostinger.web.tr/rehberler/ssh-nedir)
6. [awk command](https://www.howtogeek.com/562941/how-to-use-the-awk-command-on-linux/)
7. [sudo config](https://www.tecmint.com/sudoers-configurations-for-setting-sudo-in-linux/)
8. [List Users Commands](https://devconnected.com/how-to-list-users-and-groups-on-linux/#:~:text=In%20order%20to%20list%20users,navigate%20within%20the%20username%20list)

**🏁And finally README.md ends here..🏁**

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/matrix.gif" align="right" height="550">
