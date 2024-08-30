<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/debian_gif.gif" align="right" height="400">

# Debian

Bu kurulum için **Debian** temel alınmıştır ve **bonus bölüm** dahildir.

## 🧭 Yol Haritası

1.  [Kısım 1 - Debian Yükleme](https://github.com/Fartomy/42-Kickoff/master/Born2beroot/debian/README.tr.md#one-k%C4%B1s%C4%B1m-1---debian-y%C3%BCkleme)

2. [Kısım 2 - İndirmeler ve Ayarlamalar ve Yapılandırmalar](https://github.com/Fartomy/42-Kickoff/master/Born2beroot/debian/README.tr.md#two-k%C4%B1s%C4%B1m-2---i%CC%87ndirmeler-ve-ayarlamalar-ve-yap%C4%B1land%C4%B1rmalar)
   - [SSH için](https://github.com/Fartomy/42-Kickoff/master/Born2beroot/debian/README.tr.md#-ssh-i%C3%A7in)
   - [UFW için](https://github.com/Fartomy/42-Kickoff/master/Born2beroot/debian/README.tr.md#%EF%B8%8F-ufw-i%C3%A7in)
   - [Sudo için](https://github.com/Fartomy/42-Kickoff/master/Born2beroot/debian/README.tr.md#godmode-sudo-i%C3%A7in)
   - [Şifreleme Politikası](https://github.com/Fartomy/42-Kickoff/master/Born2beroot/debian/README.tr.md#%EF%B8%8F-%C5%9Fifreleme-politikas%C4%B1)

3. [Kısım 3 - Monitoring.sh and Crontab Yapılandırmaları](https://github.com/Fartomy/42-Kickoff/master/Born2beroot/debian/README.tr.md#3%EF%B8%8F%E2%83%A3-k%C4%B1s%C4%B1m-3---monitoringsh-ve-crontab-yap%C4%B1land%C4%B1rmalar%C4%B1)

4. [Bonus Kısım - WordPress Kurulumu ve Hizmetinizin Seçimi](https://github.com/Fartomy/42-Kickoff/master/Born2beroot/debian/README.tr.md#%EF%B8%8F%E2%83%A3-k%C4%B1s%C4%B1m-bonus---wordpress-kurulumu-ve-hizmetinizin-se%C3%A7imi)

      - [WordPress Kurulumu](https://github.com/Fartomy/42-Kickoff/master/Born2beroot/debian/README.tr.md#-wordpress-kurulumu)
         - [Lighttpd için](https://github.com/Fartomy/42-Kickoff/master/Born2beroot/debian/README.tr.md#-lighttpd-i%C3%A7in)
         - [MariaDB için](https://github.com/Fartomy/42-Kickoff/master/Born2beroot/debian/README.tr.md#-mariadb-i%C3%A7in)
         - [PHP için](https://github.com/Fartomy/42-Kickoff/master/Born2beroot/debian/README.tr.md#%EF%B8%8F-php-i%C3%A7in)
         - [WordPress için](https://github.com/Fartomy/42-Kickoff/master/Born2beroot/debian/README.tr.md#-wordpress-i%C3%A7in)
      - [Hizmetinizin Seçimi](https://github.com/Fartomy/42-Kickoff/master/Born2beroot/debian/README.tr.md#-hizmetinizin-se%C3%A7imi)

6. [Kısım 4 - Gönderim ve Akran Değerlendirmesi](https://github.com/Fartomy/42-Kickoff/master/Born2beroot/debian/README.tr.md#4%EF%B8%8F%E2%83%A3-k%C4%B1s%C4%B1m-4---g%C3%B6nderim-ve-akran-de%C4%9Ferlendirmesi)

7. [Ekstra ve Kaynaklar](https://github.com/Fartomy/42-Kickoff/master/Born2beroot/debian/README.tr.md#5%EF%B8%8F%E2%83%A3-ekstralar-ve-kaynaklar)
   - [Ekstralar](https://github.com/Fartomy/42-Kickoff/master/Born2beroot/debian/README.tr.md#-ekstralar)
   - [Kaynaklar](https://github.com/Fartomy/42-Kickoff/master/Born2beroot/debian/README.tr.md#brain-kaynaklar)
  
## :one: Kısım 1 - Debian Yükleme

Öncelikle VirtualBox'ı indirin ve Debian'ın .iso dosyasını indirin. İşte bağlantılar:

- [VirtualBox](https://www.virtualbox.org/)

- [Debian](https://www.debian.org/)

Yükleme sonrası VirtualBox'ı açın:

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/1.png" align="center" height="325">

Sonraki sonraki sonraki.. ve 'Makine Klasörü', makine klasörünüzün yolu '/goinfre' olacaktır ancak sabit disk dosya türünün vdi olmasına dikkat edin.

Daha sonra **'.iso'** Debian dosyasını seçin. Oluşturduğunuz sanal makineye tıklayın ve yukarıdaki **'ayarlar'** seçeneğine tıklayın. ve buradan **'Depolama'** seçeneğine tıklayın, **'Boş'** seçeneğine tıklayın ve sağ pencerede **'Optik Sürücü'** seçeneğinin yanındaki **CD** işaretine basın. Oradan, **'Disk Dosyasını Seç'** seçeneğine tıklayın ve indirdiğiniz debian **'.iso' dosyasını seçin.

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/2.png" align="center" height="325">

Kurulum videosu:

[Debian Kurulum Videosu](https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/setup_debian.mp4)

**🏁Ve nihayet Bölüm 1 burada bitiyor..🏁**

## :two: Kısım 2 - İndirmeler ve Ayarlamalar ve Yapılandırmalar

Bu ekranı göreceksiniz, muhtemelen bu giriş ekranıdır

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/31.png" align="center" height="300">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/32.png" align="center" height="300">

Bu komutu çalıştırarak diskinizin bölümlerini ve şifrelenmiş bölümlerini görebilirsiniz:

```
lsblk
```

İndirme ve yapılandırma işlemlerine geçmeden önce şunları bilmekte fayda var:

- Kök olmak için:

```
su -
```

- Yeni bir paket varsa tarayın:

```
apt update
```

- Güncellenmesi gereken bir paket varsa güncelleyin:

```
apt upgrade
```

### 🛎️ Hostname'i Değiştirin

Hostname'i görme komutu:

```
hostname
```

Host adını değiştirmek için aşağıdaki dosyayı nano ile girelim **(root olmalısınız)**:

```
nano /etc/hostname
```

Muhtemelen host adını göreceksiniz, evet onu değiştirin ve kaydedin:

`CTRL + O then ENTER and then CTRL + X to save and exit in nano`

Kaydettikten ve çıktıktan sonra bilgisayarı yeniden başlatın:

```
reboot
```

Eski host adınıza dönmek istiyorsanız bu adımları tekrarlayın :d

### 🧮 Kullanıcı Komutları

Bunların dışında sanal makinenizde ki kullanıcıları görmenizi sağlayacak komut:

```
getent passwd
```

Kullanıcı ekleme ve silme komutları:

```
# adduser <user_name>```
# deluser <username>
```

### 🍇 Grup Komutları

Sanal makinenizde ki grupları görme komutu:

```
# getent group```
# getent group <group_name> -> Users under a group
```

Grup ekleme ve silme komutları:

```
# groupadd <group_name>
# groupdel <group_name>
```

Örnek olarak `user42` grubunu ekleyelim:

```
groupadd user42
```

### 🤝 Kullanıcılarla kullanılan grupların komutları

Bir kullanıcının hangi grupta olduğunu görmek için ilk komut:

```
groups <user_name>
```

Bir gruba kullanıcı ekleme ve gruptan kullanıcı çıkarma komutu:

```
# usermod -aG <group_name> <user_name>
# gpasswd --delete <user_name> <group_name>
```

Şimdi kullanıcıyı `user42` grubunun altına ekleyelim:

```
usermod -aG user42 <user_name>
```

## 🛠️ Paketleri yükleme ve dosyaları yapılandırma

### 🧰 SSH için

SSH'yi yükleyin:

```
apt install openssh-server
```

SSH etkinlik sorgusu komutu ve ssh başlatma komutları:

```
# systemctl start sshd
# systemctl enable sshd
# systemctl status ssh
```

#### :dna: SSH Port'u Değişikliği

Bu dizine gitmelisiniz:

```
nano /etc/ssh/sshd_config
```

Bu ayarları değiştirmelisiniz:

```
- #Port 22 -> Port 4242
- #PermitRootLogin prohibit-password -> PermitRootLogin no
- Ve evet, '#' işaretini de kaldırın, yazdıklarınızı yorum satırına alacak yoksa. :)
- Bu arada yukarıda bahsettiğim 2 ayar için '#' işaretlerini kaldırmanız yeterli. Hepsini değil :D
```

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/33.png" height="300">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/34.png" align="center" height="300">

Tamam, bu ayarları yaptıktan sonra şu komutla yeniden başlatın:

```
systemctl restart sshd
```

Daha sonra VirtualBox'a gelin ve üstteki **'ayarlar'** tuşuna basın, ardından **'ağ'**'a basın, ardından altta **'Gelişmiş'** bölmesi olacak, oraya tıklayın ve ** tuşuna basın 'Bağlantı Noktası Yönlendirme'**. Sağda yeşil **'+'** işareti olan bir buton göreceksiniz, evet ona basın ve tablo gibi bir şey görünecektir. **'Ana Bilgisayar bağlantı noktası'** ve **'Tahmin Bağlantı Noktası'** bölümlerinde resimdeki gibi yapın. Zaten resim ekliyorum, neden açıklama ihtiyacı hissettim bilmiyorum. Neyse, tamam tamam'a basın ve bitti.

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/35.png" align="center" height="300">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/36.png" align="center" height="300">

Bunları yaptıktan sonra sanal makinenizi yeniden başlatın:

```
reboot
```

Bu ayarlardan sonra artık ana makineden sanal makineye bağlanabilirsiniz:

```
ssh your_username@localhost -p 4242
```

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/37.png" align="center" height="300">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/38.png" align="center" height="300">

Ve sanal makinenize kullanıcının şifresini girerek ana bilgisayarın terminalinden sanal makineye erişebilirsiniz.

_[@@@ Opsiyonel Problem @@@]_

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
Böyle bir durumla karşılaştığınızda yapmanız gerekenler mesajda belirtilmiştir.

**🚩Evet, SSH bu kadardı..🚩**

### 🛡️ UFW için

UFW'yi yükleyin:

```
apt install ufw
```

#### :eye_speech_bubble: UFW ile ilgili bazı komutlar

Bize yapılan tüm istekleri reddedin:

```
ufw default deny incoming
```

Tüm giden isteklere izin ver:

```
ufw default allow outgoing
```

Sistem başlangıcında UFW'yi etkinleştirin (Bunu yaptıktan sonra sanal makinenizi yeniden başlatın):

```
ufw enable
```

UFW'nin durumuna göz atın:

```
# ufw status
# ufw status numbered -> numbered the rules
```

4242 numaralı bağlantı noktasına gelen isteklere izin verin veya bu bağlantı noktasını reddedin:

```
# ufw allow 4242
# ufw deny 4242
```

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/39.png" align="center" height="300">

bir kuralı silmek için:

```
# ufw delete allow 4242 -> this command deletes 'allow' rules 4242
# ufw delete deny 4242  -> deletes 'deny' rules 4242 <br/>
# ufw delete 1 -> deletes rule 1
```

**🚩Evet, UFW bu kadardı..🚩**

### :godmode: Sudo için

`sudo`'yu çok çok katı kurallara göre yapılandırmak

Sudo'yu yükleyin:

```
apt install sudo
```

Yapılandırma ayarlarına geçmeden önce kullanıcınızı `sudo` grubunun altına ekleyin:

```
usermod -aG sudo <user_name>
```

```
visudo -> Let's enter the configuration file with this command
```

Şöyle bir ekran gelmeli:

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/40.png" align="center" height="300">

Buraya bazı katı kurallar ekleyin:
 
 ```
 Defaults     passwd_tries=3 -> 3 yanlış giriş hakkı
 Defaults     badpass_message="Wrong Password!!!" -> yanlış şifre uyarı mesajı
 Defaults     requiretty -> sudo komutu için terminal gereksinimi
 Defaults     logfile="/var/log/sudo/sudo.log" -> girilen her sudo komutunun günlükleri
 Defaults     log_input, log_output -> sudo komutlarının G/Ç'si
 Defaults     iolog_dir="/var/log/sudo/" -> giriş ve çıkış dizin yolu
```

_[@@@ İlginç Antik Bilgiler @@@]_

{requiretty}

Uzaktaki bir sisteme SSH aracılığıyla tam olarak bağlanmadan komutları ve komut dosyalarını uzaktan çalıştırmamızı engeller.

Ana makinenizde bu komutu deneyin:

```
ssh your_username@localhost -p 4242 'echo 'your_pass' | sudo -S ls -al'
```

Veya bir komut dosyası oluşturup bu komutu yapıştırıp komut dosyasını çalıştırabilirsiniz. tty gerektirdiğinden çalışmayacak.

Komutu ssh ile gönderebiliriz ancak tırnak işaretleri ('') arasında olması gerekir. Sudo şifresi için `-S` seçeneğini kullanmalıyız ve bunu `echo` ile gönderebiliriz.

{secure_path}
```
Ortam Değişkenleri (Ortam Değişkenleri) Nedir?
Ortam değişkenleri, işletim sisteminin ve uygulamaların yapılandırma bilgilerini depolamak ve paylaşmak için kullandığı genel değişkenlerdir. Bu değişkenler sistem veya oturum genelinde geçerli olan çeşitli ayarları ve tercihleri ​​içerir.

En Yaygın Ortam Değişkenlerinden Biri: PATH
PATH ortam değişkeni, işletim sisteminin komutları aradığı dizinlerin bir listesini içerir. Örneğin, komut satırına ls komutunu yazdığınızda sistem, ls komutunu PATH'de tanımlanan dizinlerde arar.
PATH, çeşitli dizin yolları arasında : karakteriyle ayrılan bir listedir. Örneğin: /usr/bin:/bin:/usr/sbin:/sbin
sudo ve secure_path
sudo, bir komutu süper kullanıcı (kök) haklarıyla çalıştırmanıza izin veren bir araçtır. sudo kullanıldığında, güvenlik nedeniyle sistem, PATH ortam değişkenini kullanmak yerine sudoers dosyasındaki secure_path ayarını kullanır.

secure_path İşlevi:
Sudo ile bir komut yürütüldüğünde, secure_path'te tanımlanan yollar, komutu aramak için güvenli dizinler olarak kullanılır.
Bu, kullanıcıların veya komut dosyalarının sudo ile güvenli olmayan dizinlerde komut yürütmesini engeller.
Örnek Senaryo ve Açıklama
Diyelim ki sisteminizde /custom/bin adında bir dizin var ve bu dizin secure_path'te tanımlı değil. Bu dizinde testcommand adında bir komutun olduğunu varsayalım.

Bir Komutu Normal Kullanıcı Olarak Çalıştırmak:

Kullanıcı olarak /custom/bin/testcommand komutunu çalıştırdığınızda sistem PATH ortam değişkenini kullanır ve komut çalışır.
Sudo ile bir Komut çalıştırmak:

sudo/custom/bin/testcommand komutunu çalıştırdığınızda sudo, secure_path'i kullanır.
Eğer /custom/bin güvenli_yolda tanımlanmamışsa, sudo bu komutu bulamayacak ve çalıştıramayacaktır. Bu, Sudo'nun yalnızca secure_path'te tanımlanan yolları kullandığını gösterir.
Test
Bu durumu test etmek için:

/custom/bin/testcommand (veya başka bir dizin/komut) oluşturun.
Bu dizini PATH'e ekleyin: Export PATH=$PATH:/custom/bin
Komutu normal bir kullanıcı olarak çalıştırın: /custom/bin/testcommand
sudo ile çalıştır: sudo/custom/bin/testcommand
Sudo komutu "komut bulunamadı" hatası veriyorsa, bu secure_path'in çalıştığını gösterir.
```

Sonuncusu şöyle görünmeli:

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/41.png" align="center" height="300">

Bunları onaylamak için _root_'tan çıkıp `sudo` komutuyla neler yapılabileceğini deneyebilirsiniz.

**🚩Evet, `sudo` bu kadardı..🚩**

### ⛓️ Şifreleme Politikası

Öncelikle şifre değiştirme sıklığını yapılandırın:

```
nano /etc/login.defs
```
Şu şekilde bulabilirsiniz _Password aging control_:

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/42.png" align="center" height="300">

Daha sonra bunu şu şekilde yapın:

```
PASS_MAX_DAYS   30
PASS_MIN_DAYS   2
PASS_WARN_AGE   7
```

_**⚠️Evet bu kadar ama bu ayar root ve sizden (usr) sonraki kullanıcılar için geçerlidir. Kullanıcınızı ve kökünüzü değiştirmek için bunu yapın⚠️**_

Öncelikle size şunu kanıtlayayım:

```
# chage -l root
# chage -l <user_name> -> I think that's a enough proof :()
```

Değiştirmek için:

```
# chage root
# chage <user_name>
```

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/43.png" align="center" height="300">

Ne yapacağını biliyorsun..

Şimdi şifre oluşturma kurallarımızı ekleyelim

Yükleyin:

```
apt install libpam-pwquality
```

Daha sonra şu yolu izleyin:

```
nano /etc/security/pwquality.conf
```

Şöyle bir şeyle karşılaşacaksınız:

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/44.png" align="center" height="300">

İşte değiştirmeniz gerekenler:

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

Açıklama yazmayacağım, zaten yazılmış :()

_**⚠️Evet, hepsi bu, ancak bunları yaptıktan sonra yine de root'un, kullanıcınızın ve oluşturduysanız diğer tüm kullanıcıların şifrelerini değiştirmeniz gerekiyor.⚠️**_

Nasıl mı?

```
# passwd root
# passwd <user_name>
```

**🏁Ve nihayet 2. Bölüm burada bitiyor..🏁**

## 3️⃣ Kısım 3 - Monitoring.sh ve Crontab Yapılandırmaları

### 🗒️ Monitoring.sh

İncelemek isterseniz yukarıda _monitoring.sh_ dosyasını paylaştım.

[Monitoring.sh](https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/monitoring.sh)

### ⏰ Crontab (cron)

Bu komutu yazın:

```
crontab -e
```

[mini bir bilgi]

```
Crontab -e komutu, işlemi gerçekleştiren kullanıcıya ait bir crontab dosyasını düzenlemenizi sağlar.

Örneğin kullanıcı1 kullanıcısı crontab -e komutunu kullanarak bir crontab görevi eklediğinde, bu görev kullanıcı1 kullanıcısına ait crontab dosyasına eklenir.
Diğer kullanıcılar bu dosyayı göremez ve düzenleyemez.

Kullanıcının crontab dosyasına erişmek için genellikle sistem bağlamındaki `/var/spool/cron/crontabs` veya `/var/spool/cron` gibi özel bir klasör kullanılır. 
Ancak bu dosyalar doğrudan düzenlenmemelidir; Bunun yerine 'crontab -e' kullanılmalıdır çünkü bu komut dosyaların yapısını korur ve kullanıcıya güvenli bir düzenleme ortamı sağlar.
```

Neyse, altına şunu yazın:

```
*/10 * * * * bash /your/monitoring.sh_path
```

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/45.png" align="center" height="300">

**🏁Ve nihayet 3.Bölüm burada bitiyor..🏁**

## *️⃣ Kısım Bonus - WordPress Kurulumu ve Hizmetinizin Seçimi

### 🪑 Wordpress kurulumu

#### 🪥 Lighttpd için

**Lighttpd**'yi Debian'a yüklemek için aşağıdaki komutu kullanın:

```
apt install lighttpd -y
```

**Lighttpd** hizmetini etkinleştirin:

```
# systemctl start lighttpd
# systemctl enable lighttpd
# systemctl status lighttpd
```

**Lighttpd** için **UFW** ayarları:

```
ufw allow 80
```

**VirtualBox** üzerindeki _port yönlendirme_ ayarlarından _80_ numaralı bağlantı noktasını iletin.

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/rocky/materials/41.png" align="center" height="300">

#### 🧼 MariaDB için

**MariaDB**'yi yükleyin:

```
apt install mariadb-server mariadb-client -y
```

**MariaDB** hizmetini etkinleştirin:

```
# systemctl start mariadb
# systemctl enable mariadb
# systemctl status mariadb
```

Sunucunuzda **MariaDB** yüklüyse, bir güvenlik komut dosyası çalıştırarak **MariaDB**'nizin güvenliğini sağlamanız gerekir:

```
mysql_secure_installation
```

```
Output
Enter current password for root (enter for none): 
You already have your root account protected, so you can safely answer 'n'. 
Switch to unix_socket authentication [Y/n] n
You already have your root account protected, so you can safely answer 'n'. 
Change the root password? [Y/n] Y
New password: 
Re-enter new password: 
Remove anonymous users? [Y/n] Y
Disallow root login remotely? [Y/n] Y
Remove test database and access to it? [Y/n] Y
Reload privilege tables now? [Y/n] Y
```

Artık **MariaDB**'nize erişmek için aşağıdaki komutu kullanabilirsiniz:

```
mysql -u root -p
```

### 🕯️ PHP için

**FastCGI** desteğiyle **PHP-FPM**'yi etkinleştirmek için öncelikle **PHP**'yi gerekli uzantılarla birlikte yüklemeniz gerekir.
Bunun için aşağıdaki komutu kullanabilirsiniz:

```
apt install php php-cgi php-fpm php-mysql -y
```

Daha sonra, _php.ini_ dosyasını düzenlemeniz gerekir (burada _X_, php sürümünüzdür):

```
nano /etc/php/X.X/fpm/php.ini
```

Aşağıdaki satırı bulun **yorumu kaldır** ve aşağıda gösterildiği gibi **1** olarak değiştirin:

```
cgi.fix_pathinfo=1
```

**PHP** varsayılan olarak UNIX soketi `/var/run/php/phpX.X-fpm.sock`'a işaret eder. Bu nedenle, **PHP-FPM** havuzunu **PHP**'yi **TCP** soketini dinleyecek şekilde yapılandırmanız gerekecektir.

Bunu `/etc/php/X.X/fpm/pool.d/www.conf` dosyasını düzenleyerek yapabilirsiniz:

```
nano /etc/php/X.X/fpm/pool.d/www.conf
```

Aşağıdaki satırı bulun:

```
listen = /run/php/php8.2-fpm.sock
```

Ve onu aşağıdaki satırla değiştirin:

```
listen = 127.0.0.1:9000
```

Ardından, **Lighttpd** yapılandırma değişikliklerini uygulamak için **PHP-FPM** hizmetini yeniden başlatın:

```
systemctl restart phpX.X-fpm
```

Daha sonra, _15-fastcgi-php.conf_ dosyasını değiştirmeniz gerekecektir:

```
nano /etc/lighttpd/conf-available/15-fastcgi-php.conf
```

Dosyada aşağıdaki satırları bulun:

```
fastcgi.server += ( ".php" =>
((
"bin-path" => "/usr/bin/php-cgi",
"socket" => "/run/lighttpd/php.socket",
...
))
)
```

Ve bunları aşağıdakilerle değiştirin:

```
"host" => "127.0.0.1",
"port" => "9000",
```

Ardından, aşağıdaki komutlarla hem **FastCGI** hem de **FastCGI-PHP** modüllerini etkinleştirin:

```
# lighty-enable-mod fastcgi
# lighty-enable-mod fastcgi-php
```

Son olarak değişiklikleri uygulamak için **Lighttpd** hizmetini yeniden başlatın:

```
systemctl restart lighttpd
```

Bu yola `/var/www/html` gidin ve `index.html` dosyasını silin:

```
rm -rf index.html
```

**PHP** testi için `info.php` dosyasını oluşturun:

```
nano info.php
```

Bu satırları dosyaya yazın:

```
<?php
phpinfo();
?>
```

Tarayıcınızda kontrol edin:

```
http://localhost:8080/info.php
```

### 🎬 WordPress için

Öncelikle şu paketleri kurmalısınız:

```
apt install -y wget unzip
```

**WordPress** paketlerini indirin:

```
wget https://wordpress.org/latest.zip
```

Dosyaları çıkart:

```
unzip latest.zip
```

Okuma ve yazmada sorun yaşamamak için bazı izin ayarlarını düzenleyelim:

```
# find wordpress/ -type d -exec chmod 755 {} \;
# find wordpress/ -type f -exec chmod 644 {} \;
```

WordPress dizinine girin ve dosyaları `/var/www/html/` dizinine kopyalayın:

```
cp -r * /var/www/html/
```

**MariaDB**'de **WordPress** için bir veritabanı ve kullanıcı oluşturalım:

```
mysql -u root -p
```

**MariaDB**'de aşağıdaki komutları yürütün:

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

Son olarak **MariaDB**'den _exit_.

Artık WordPress kurulum sayfasına gidebiliriz:

```
http://localhost:8080/index.php
```

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/rocky/materials/52.png" align="center" height="300">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/rocky/materials/53.png" align="center" height="300">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/rocky/materials/54.png" align="center" height="300">


Sistemdeki `wp-config.php` dosyasına yazma izniyle ilgili sorun yaşıyoruz.

```
chown -R www-data:www-data /var/www/html/
```

Tekrar deneyin.

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/rocky/materials/55.png" align="center" height="300">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/rocky/materials/56.png" align="center" height="300">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/rocky/materials/57.png" align="center" height="300">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/rocky/materials/58.png" align="center" height="300">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/rocky/materials/59.png" align="center" height="300">

Son olarak, şu `/var/www/html/` yolundaki `index.lighttpd.html` dosyasını yeniden adlandırmalı veya silmelisiniz:

```
# mv /var/www/html/index.lighttpd.html /var/www/html/d.html
or
# rm -rf /var/www/html/index.lighttpd.html
```

Ana sayfanızı ziyaret edin:

```
http://localhost:8080
```

### 📺 Hizmetinizin Seçimi

Benim seçimim _Python http sunucusuna_ hizmet vermek.

Bunun için önce `python3` paketini kurun:

```
apt install -y python3
```

_UFW_'da gerekli bağlantı noktası izinlerini verin:

```
ufw allow 5050
```

VirtualBox ayarlarındaki **port yönlendirme** ayarından _5050_ bağlantı noktasını ekleyin:

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/35.png" align="center" height="300">

Hizmeti oluşturmak için `/etc/systemd/system` dizininde `python-http-server.service` adında bir dosya oluşturun:

```
nano /etc/systemd/system/python-http-server.service
```

İçine şunları yazın:

```
[Unit]
Description=Python HTTP Server

[Service]
ExecStart=/usr/bin/python3 -m http.server 5050
WorkingDirectory=/directory/path/to/be/presented/on/the/browser
Restart=always
User=user_name

[Install]
WantedBy=multi-user.target
```

Kaydedip çıktıktan sonra hizmeti başlatmak için:

```
# systemctl enable python-http-server.service
# systemctl start python-http-server.service
# systemctl status python-http-server.service
```

Etkinse tarayıcı aracılığıyla erişin:

```
http://localhost:5050
```

**🏁 Ve son olarak Bonus Kısmı burada bitiyor.. 🏁**

## 4️⃣ Kısım 4 - Gönderim ve Akran Değerlendirmesi

Artık her şey bittiğine göre disk imzanızı almanın zamanı geldi:

Öncelikle _/goinfre_ dizinine kurduğumuz dosyaya girip sanal makinenizi bulmalısınız.
Buranın nerede olduğunu bilmediğim için oraya gittiğinizi varsayıyorum.

Bunu yazın:

```
shasum <your_virtual_machine>.vdi
```

Disk imzanız geldiğinde `signature.txt` dosyasına gönderip push alacaksınız. Hepsi bu. Buraya kadar geldiyseniz, 🥳TEBRİKLER!!!🥳

**🏁Ve nihayet 4.Bölüm burada bitiyor..🏁**

## 5️⃣ Ekstralar ve Kaynaklar

### ➕ Ekstralar

1-) Arkadaşınızın sanal makinesine SSH kullanarak bağlanabilirsiniz.

2-) _netcat_ ile arkadaşlarınızla terminal üzerinden sohbet edebilirsiniz.

Malzemeler:

- IPv4 adresi
```
# apt install net-tools
# ifconfig
```

- Port

```
netstat -anvp tcp | awk 'NR<3 || /LISTEN/' -> find open port
```

🥂 NetCat nasıl kullanılır?

Öncelikle arkadaşınızın bilgisayarının açık portunu terminale yazın:

```
nc -l <port -> ve GİRİN. ve arkadaşını bekle. Daha sonra kendi bilgisayarınıza gidin
```

Bundan sonra arkadaşınızın _IPv4_ adresini ve port numarasını yazın ve _ENTER_ tuşuna basın.
Mesajlaşma başlasın!

```
nc <IPv4_adress> <port>
```

☣️ Debian kullanıcı ve root şifrelerinizi unutursanız

[Debian Password Reset](https://www.youtube.com/watch?v=3Hrm3_CFKic)

### :brain: Kaynaklar

1. [Aptitude vs apt](https://dijitalders.net/icerik/22/2369/apt_get_ve_aptitude.html)
2. [Sudo](https://medium.com/@gokhansengun/sudo-nas%C4%B1l-kullan%C4%B1l%C4%B1r-ve-incelikleri-nelerdir-52db87d74ba)
3. [SElinux](https://www.redhat.com/en/topics/linux/what-is-selinux)
4. [AppArmor](https://apparmor.net/)
5. [SSH](https://www.hostinger.web.tr/rehberler/ssh-nedir)
6. [awk command](https://www.howtogeek.com/562941/how-to-use-the-awk-command-on-linux/)
7. [sudo config](https://www.tecmint.com/sudoers-configurations-for-setting-sudo-in-linux/)
8. [List Users Commands](https://devconnected.com/how-to-list-users-and-groups-on-linux/#:~:text=In%20order%20to%20list%20users,navigate%20within%20the%20username%20list)
9. [Lighttpd Setup on Debian](https://orcacore.com/install-lighttpd-web-server-debian-12/)
10. [Wordpress Setup Video](https://www.youtube.com/watch?v=PsMhopODLTY&t=565s)
11. [Wordpress Setup Video 2](https://www.youtube.com/watch?v=PhNxEZcxXV0)

**🏁Ve son olarak README.md burada bitiyor..🏁**

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/materials/matrix.gif" align="right" height="550">
