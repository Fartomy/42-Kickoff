<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Inception/imgs/Tesseract.gif" align="right" height="500">

# Inception

Bu kurulum **Inception** ve **bonus bölümü** içerir.

## 🧭 Yol Haritası
1. [Preparation](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#one-part-1---preparation)
   - [Install Packages](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#install-packages)
   - [Configuration](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#configurations)
   - [VS Code Remote Connection](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#vs-code-remote-connection)
   - [For Using Docker Commands Without Sudo](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#for-using-docker-commands-without-sudo)
2. [Inception](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#two-part-2---inception)
   - [PID 1](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#pid-1)
   - [CMD - ENTRYPOINT](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#cmd---entrypoint)
   - [About .sh Files](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#about-sh-files)
   - [Security of Using Password in Dockerfile](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#security-of-using-password-in-dockerfile)
   - [When to Transfer ENV Values ​​to a Container?](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#when-to-transfer-env-values-to-a-container)
   - [How Does .env File Work in Docker?](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#how-does-env-file-work-in-docker)
   - [DBRFCWEVFWRWE-C](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#difference-between-running-a-sh-file-created-with-envs-or-values-in-the-env-file-with-run-or-with-entrypoint-cmd)
   - [About Latest Tag](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#tags-of-docker-images-and-docker-compose-be-latest-by-default-and-can-be-changed)
   - [Getting Config Files of Services With docker cp](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#getting-config-files-of-services-with-docker-cp)
   - [docker inspect/logs/attach Commands](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#docker-inspectlogsattach-commands)
3. [Services](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#three-part-3---services)
   - [For Nginx](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#yarn-for-nginx)
   - [For WordPress](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#thread-for-wordpress)
   - [For MariaDB](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#sewing_needle-for-mariadb)
4. [~ B O N U S ~](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#four-part-4----b-o-n-u-s-)
   - [For Adminer](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#plunger-for-adminer)
   - [For Website](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#placard-for-website)
   - [For Redis](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#fire_extinguisher-for-redis)
   - [For FTP Server](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#sponge-for-ftp-server)
   - [For Own Service](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#window-for-own-service)
   - [For QEMU Service](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#paintbrush-for-qemu-service)
5. [Sources](https://github.com/Fartomy/42-Kickoff/blob/master/Inception/README.md#paperclip-sources)
   - [VS Code](https://github.com/Fartomy/42-Kickoff/tree/master/Inception#vs-code)
   - [Docker Essentials](https://github.com/Fartomy/42-Kickoff/tree/master/Inception#docker-essentials)
   - [Nginx](https://github.com/Fartomy/42-Kickoff/tree/master/Inception#nginx)
   - [WordPress](https://github.com/Fartomy/42-Kickoff/tree/master/Inception#wordpress)
   - [MariaDB](https://github.com/Fartomy/42-Kickoff/tree/master/Inception#mariadb)
   - [B O N U S](https://github.com/Fartomy/42-Kickoff/tree/master/Inception#b-o-n-u-s)
     - [Adminer](https://github.com/Fartomy/42-Kickoff/tree/master/Inception#adminer)
     - [Website](https://github.com/Fartomy/42-Kickoff/tree/master/Inception#website)
     - [Redis](https://github.com/Fartomy/42-Kickoff/tree/master/Inception#redis)
     - [FTP Server](https://github.com/Fartomy/42-Kickoff/tree/master/Inception#ftp-server)
     - [Own Service](https://github.com/Fartomy/42-Kickoff/tree/master/Inception#own-service-1)

## :one: Kısım 1 - Ön Hazırlık

Bu kurulum **Debian** tabanlıdır ancak herhangi bir dağıtımda seçilebilir.
Bunun için sizi tanıdık kurulum talimatlarına yönlendireceğim. [B2B](https://github.com/Fartomy/42-Kickoff/blob/master/Born2beroot/debian/README.tr.md#one-k%C4%B1s%C4%B1m-1---debian-y%C3%BCkleme).

### VirtualBox Ağ Ayarı

Port yönlendirmeleriyle uğraşmak zorunda kalmamak için, Vbox'taki ağ ayarlarında _**NAT**_ ayarını _**Köprü Bağdaştırıcısı**_ olarak değiştirin.

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Inception/imgs/vboxbridgenetwork.JPG" align="center" height="800">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Inception/imgs/bridgenetwork2.JPG" align="center" height="800">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Inception/imgs/bridgenetwork3.JPG" align="center" height=800">

### Paketleri Yükle

Docker ve docker-compose'u kullanmak ve gerekli testleri gerçekleştirmek için bir tarayıcı, uzaktan bağlantı için bir ssh-sunucusu, ilkel ama kullanımı basit bir masaüstü ortamı ve bir terminal programı gereklidir.
Son olarak kök ayrıcalıkları için bir sudo. </br> </br>

_(Not: Ayrıca UFW kurmak istiyorsanız gerekli ayarlamaları yapmanız gerektiğini unutmayın. UFW bu dokümantasyona dahil değildir.
Bunun sebebini yukarıda benzer bir davranışını yaptığım B2B rehberliğimdeki üşengeçliğimden anlayabilirsiniz.)_

```
apt install sudo ssh docker docker-compose openbox xinit kitty firefox-esr -y
```

Masaüstü ortamına girmek için yazılacak komut (root gereklidir):
```
startx
```

İçeriği siyah ekranda **sağ tıklayarak** görebilirsiniz.

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Inception/imgs/openboxusage.JPG" align="center" height="800">

### Yapılandırmalar

Yine üşengeçliğimin bir yansıması olarak **sudo** ve **ssh** konfigürasyonları için bazı yönlendirmeler vereceğim.

#### Sudo Mini Config
Sudo için, sudo yapılandırma dosyasındaki kök satırının altına `<kullanıcı adınız> ALL=(ALL:ALL) ALL` yazmanız yeterlidir. </br>
[Sudo Yapılandırması](https://github.com/Fartomy/42-Kickoff/tree/master/Born2beroot/debian#godmode-for-sudo)

#### SSH Mini Config
SSH için, bağlantı noktası satırındaki yorum satırını kaldırabilir ve ona istediğiniz bir bağlantı noktası numarası verebilirsiniz. İsteğe bağlı olarak, kök oturum açma izni için "PermitRootLogin"i "evet" olarak ayarlayın. </br>
[SSH Yapılandırması](https://github.com/Fartomy/42-Kickoff/tree/master/Born2beroot/debian#-for-ssh)

Unutmayın:
```
# systemctl start sshd
# systemctl enable sshd
# systemctl status sshd
```

### VSCode Uzaktan Bağlantı
Bir sonraki bölümde neden bu kadar üşengeç olunduğunu daha iyi anlamak için bu üşengeçliği daha fazla uzatmayıp son kez kullanarak geleceğe yatırım yapın.

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Inception/imgs/vscoderemote.JPG" align="center" height="800">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Inception/imgs/vscoderemote2.jpg" align="center" height="800">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Inception/imgs/vscoderemote3.jpg" align="center" height="800">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Inception/imgs/vscoderemote4.jpg" align="center" height="800">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Inception/imgs/vscoderemote5.jpg" align="center" height="800">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Inception/imgs/vscoderemote6.jpg" align="center" height="800">
<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Inception/imgs/vscoderemote7.jpg" align="center" height="800">

Buna benzer bir hata alırsanız: </br>

`Failed to connect to the remote extension host server`

Bağlandığınız sanal makinede kullanıcının _home_ dizinine gidin ve aşağıdaki gizli dosyayı silin:
```
rm -rf .vscode-server
```
Ardından VM'ye `wget` ve `curl` paketlerini yükleyin:
```
apt install wget curl -y
```
Ve tekrar bağlanmayı deneyin. </br>

Bağlandıktan sonra istediğiniz dizini açmak için (örneğin bu proje için oluşturulan dizin olabilir), vscode terminalinden dizine gidin ve `code ` yazın.

### Docker Komutlarını Sudo Olmadan Kullanmak İçin

1. docker grubu oluşturma
```
sudo groupadd docker
```
ya da
```
sudo addgroup docker
```
2. Docker grubuna kullanıcı ekleyin
```
sudo usermod -aG docker $USER
```
3. Değişikliklerin etkili olması için oturumu kapatıp tekrar açın veya bu komutu çalıştırın.
```
newgrp docker
```
4. Docker grubunda olup olmadığınızı kontrol edin
```
id <user_name>
```

**🏁Ve nihayet Kısım 1 burada bitiyor..🏁**

## :two: Kısım 2 - Inception

Burada docker komutlarını açıklamayacağım. Bu konuyla ilgili tonlarca kaynak bulabilirsiniz. Burada özellikle değinmek istediğim bazı çalışma prensiplerini, 
kendimce hoşuma giden ve işleri kolaylaştıran bazı komutları inceleyeceğiz.

### PID 1
Docker konteynerlerinde **PID 1**, genellikle Dockerfile'da belirtilen başlatma komutu veya komutlarıdır. 
Bu komutlar, konteyner başlatıldığında PID 1 olarak çalıştırılır.
Bu komutlar, CMD veya ENTRYPOINT komutları kullanılarak belirlenir.

Yani, Docker konteynerlarında PID 1'in işlevi genellikle Dockerfile'da belirtilen başlatma komutunu veya komutlarını yürütmektir.
Bu, konteynerın başlangıcını ve sonunu yönetmek için çok önemlidir ve konteynerın sağlıklı bir şekilde çalışmasını sağlar.

Bu yüzden konteynerların içine girip örneğin `mariadb` servisini `restart` yaptığımızda yani şu şekilde bir komut argümanı kullanılınca `service mariadb restart` konteyner kendisini kapatıyor.
Aslinda yaptığımız müdahale PID 1 işlemine olduğundan konteyner kendisini kapatıyor.


Bunu doğrulamak için herhangi bir konteynera girin ve aşağıda ki komutları uygulayın:
```
$ apt install psmisc -y
$ pstree
```

### CMD - ENTRYPOINT
Bu iki talimat docker image'i build olurken değil, build olduktan sonra konteynerı başlattığımızda çalışır.

### .sh Dosyaları Hakkında
`CMD` veya `ENTRYPOINT` talimat komutlarına argüman olarak verilen .sh dosyalari Dockerfile image'i build edilirken değil, konteyner başlatılınca çalışır.
Bu yüzden `docker ps` yazılınca ilgili konteynerin `COMMAND` kısmında `.sh` dosyasını görürüz.
Hatta bu konteynerin PID 1'dir bu kapanırsa veya .sh dosyasında bir hata olursa konteynerde kapanır. Çünkü konteynerin ilk process'i kapanmış olur.

### Dockerfile'da Hassas Bilgilerin Güvenliği

Docker dosyaları admin ve kullanıcı adı bilgileri ile şifreleri vb. içerebilir. Bunların kullanımı çok güvenli olmayabilir.
Bu nedenle bunları bir ortam değişkeni ile argüman olarak dışa aktarmak veya `.env` dosyası hazırlamak daha doğru olacaktır.

### ENV değerleri ne zaman konteynera aktarılır?

Çevre değişkenleri, Docker konteynerine yüklenme işlemi genellikle Docker çalışma zamanında gerçekleşir.
Bu işlem, Docker konteyneri çalıştırıldığında veya başlatıldığında gerçekleşir.

Docker Compose veya Dockerfile'da belirtilen .env dosyasında ki değerler, Docker çalışma zamanında konteynerin çevre değişkenleri bölümüne aktarılır.
Bu işlem, Docker'ın çalışma zamanı sırasında yapılır ve Docker konteyneri başlatıldığında bu değişkenler kullanılabilir hale gelir.

Yani, .env dosyasındaki değerler Docker konteynerinin çevre değişkenleri bölümüne Docker çalışma zamanında yüklenir ve Docker konteyneri başlatıldığında bu değişkenler kullanılabilir hale gelir.

Bu sayede, Docker konteynerleri çalışma zamanında esnek bir şekilde yapılandırılabilir ve .env dosyasındaki değişkenlerin kullanılmasıyla çevre değişkenleri kolayca yönetilebilir.

### .env Dosyası Docker'da Nasıl Çalışır?

Docker Compose'da bir servis de `env_file:` olarak kullandığımız bölüm de belirttigimiz `.env` dosyası o konteynerin env'sinde bizim o dosya da belirttiğimiz değerleri yerleştiriyor. 
Kontrol etmek için:
```
docker exec <container_name> env
```

### .env Dosyasında ki değerlerle oluşturulan bir .sh dosyasını  RUN ile çalıştırmak veya ENTRYPOINT-CMD ile çalıştırmak arasında ki fark

.sh dosyasını Dockerfile içerisinde `RUN` komutu ile çalıştırdığınızda .env dosyasında ki değişkenlerin henüz tanımlanmadığı bir ortamda çalıştırılır.
</br>
Bunun aksine, .sh dosyasını Docker dosyasında `ENTRYPOINT-CMD` komutuyla çalıştırdığınızda, bu dosyayı çalışma zamanında çalıştırmadan önce,
Docker ortamı hazırlar ve .env dosyasındaki değişkenler tanımlanır. Bu nedenle .sh dosyası çalıştırıldığında değişkenler doğru şekilde aktarılır.
</br>
`ENTRYPOINT-CMD` komutu çalışma zamanında, yani konteyner başlatıldığında çalışır ve bu nedenle .env dosyasındaki değişkenler kullanılmadan önce tanımlanır.

### Docker image'lerin tag'lerinin `latest` olmamasını sağlama ve docker-compose tag ayarı

Normal de Dockerfile image'lerini build ederken bu şekilde `latest` tag'inden kaçılınabilir:
```
docker build -t my_image:1.0 .
```
Docker Compose'da ise bir servisin altında şu talimatı vererek `latest` tag'inden kaçılınabilir:
```
services:
  mariadb:
    image: mariadb:not-latest -----> like
    container_name: mariadb
    build: ./requirements/mariadb
    env_file:
      - .env
    volumes:
      - mariadb-data:/var/lib/mysql
    networks:
      - docker-network
    restart: always
```

### 'docker cp' ile servislerin yapılandırma dosyalarını alma
Bu komutla servislerin config dosyalarını hosta kopyaladım.

Kullanım:
**Dosyaları konteynerdan ana bilgisayara kopyalama:**
```
docker cp CONTAINER_ID_OR_NAME:/path/to/container/file_or_directory /path/to/host/destination
```
Örnek:
```
docker cp my_container:/app/logs/access.log /host/logs
```
**Dosyaları ana bilgisayardan kapsayıcıya kopyalama:**
```
docker cp /path/to/host/file_or_directory CONTAINER_ID_OR_NAME:/path/to/container/destination
```
Örnek:
```
docker cp /host/config/nginx.conf my_container:/etc/nginx/nginx.conf
```

### `docker inspect/logs/attach` komutları

konteynerin detaylarını veya konteyner çöktüyse, konteyner _exited_ diyorsa, başlamıyorsa nedenini öğrenmek için yazılan şeye bağlı olarak
bütün çıktıları veya güncel basılan/basılacak çıktıları görmek için bu komutlar kullanılabilir.

`inspect` ile konteynerin detaylarını incelemek için kullanılabilir. Hangi ağa bağlı, hacimlendirilmiş mi, vb. ayrıntıları görmek için kullanılabilir:
```
docker inspect <container_name>
```
`logs` ile, konteynerin başlangıcından itibaren konteyner terminale ne çıktı basmışsa bütün hepsini verir:
```
docker logs <container_name>
```
ya da
```
docker container logs <container_name>
```
Konteyner güncel olarak bir şeyin sürekli çıktısını terminale basıyorsa ve bunu görmek istiyorsak kullanılabilir ancak `logs` gibi bütün çıktıları değil en son güncel basılacak çıktıyı gösterir.
```
docker attach <container_name>
```

**🏁Ve nihayet Kısım 2 burada bitiyor..🏁**

## :three: Kısım 3 - Servisler

### :yarn: Nginx için

#### `openssl` ile oluşturulan .cert dosyaları nelerdir?
Bu sertifikalar dijital olarak imzalanmış veri yapılarıdır ve genellikle bir kişinin, kuruluşun veya cihazın kimliğini doğrulamak için kullanılır.
Örneğin, bir web sunucusunun SSL/TLS sertifikası, sunucunun kimliğini doğrulamak için web tarayıcılarına sunulur.
</br> </br>
OpenSSL gibi araçlarla oluşturulan .cert dosyaları genellikle bir kök sertifika yetkilisinin (CA) imzasını taşır.
Bu kök sertifika yetkilisi, dijital bir kimlik doğrulama hizmeti sağlar ve genellikle bir web sitesinin, bir e-posta sunucusunun veya bir ağ cihazının kimliğini doğrulamak için kullanılır.

Bu sertifikalar genellikle aşağıdaki bilgileri içerir:

- Sahip (bir web sitesi, kuruluş veya cihaz gibi)
- Sertifikanın Sona Erme Tarihi ve Geçerlilik Süresi
- Sertifika Seri Numarası
- Genel anahtara ve onunla ilişkili özel anahtara yapılan atıflar
- Sertifika İmzası ve İmzalayan Bilgileri

Bu dosyalar güvenli iletişim kurmak ve kimlik doğrulama sağlamak için çok önemlidir. Örneğin bir web tarayıcısı, kullanıcının bir web sitesine güvenli bir şekilde bağlanabilmesi için sunucunun bu tür bir sertifikaya sahip olmasını bekler.

#### Let's Encrypt VS kendinden imzalı Sertifika ve Certbot Aracı

**Let's Encrypt** Sertifika yalnızca internet üzerinden herkese açık olarak erişilebilen gerçek alan adları için geçerlidir. Localhost için Let's Encrypt sertifikası kullanmak mümkün değildir ve mantıklı değildir.
</br> </br>
Çünkü localhost, tanım gereği yalnızca sizin erişebileceğiniz bir sistemdir ve bu durumda kendinden imzalı bir sertifika tamamen yeterlidir.
</br> </br>
Certbot, Let's Encrypt sertifikalarını almak için kullanılan bir araçtır ve bu sertifikalar gerçek alan adları içindir. Localhost için Certbot ile Let's Encrypt sertifikası almaya çalışmak anlamsızdır.
</br> </br>
Peki Kendinden İmzalı Sertifika nedir? Kendinden imzalı sertifika, kendiniz oluşturup imzaladığınız bir sertifikadır. Bu sertifika, sertifika yetkilisi tarafından imzalanmadığından web tarayıcıları tarafından güvenilmez olarak işaretlendi. 
Ancak yerel geliştirme veya test ortamları gibi yalnızca kendinizin erişebileceği ortamlarda kullanılabilir. Localhost için kendinden imzalı bir sertifika oluşturmak istiyorsanız OpenSSL gibi araçları kullanabilirsiniz.
Ancak bu sertifikanın güvenilmez olarak işaretleneceğini ve tarayıcınızda bir güvenlik uyarısı görüntüleyebileceğini unutmayın.

#### Alan adını yerel IP adresine işaret edecek şekilde yapılandırma

`/etc/hosts` dizininden `127.0.0.1 localhost` yazan satıra aşağıdaki alan adını eklemek `127.0.0.1 localhost user_name.42.fr` durumu çözecektir.

```
127.0.0.1       localhost user_name.42.fr
127.0.1.1       debian

# The following lines are desirable for IPv6 capable hosts
::1     localhost ip6-localhost ip6-loopback
f206::2 ip6-allnodes
f104::0 ip6-allrouters
```

#### `daemon off;` Nedir?

`daemon off;` İfade, Nginx yapılandırma dosyasında bulunan bir yönergedir. Bu yönerge, Nginx'in bir daemon (arka plan hizmeti) olarak çalışmasını engeller ve Nginx'in ana süreç olarak çalışmasına izin verir.
</br> </br>
Normalde Nginx başlatıldığında bir daemon olarak çalışır ve arka planda ana iş parçacığını çalıştırır. Bu, Nginx'in sunucu işlevlerini gerçekleştirmesine ve istemcilere hizmet vermesine olanak tanır.
Ancak bazı durumlarda, özellikle geliştirme veya hata ayıklama sırasında, Nginx'i bir arka plan programı olarak değil, doğrudan terminalde çalıştırmak isteyebilirsiniz.
</br> </br>
`daemon off;` direktifi Nginx'in daemon modunu devre dışı bırakarak Nginx'i ön planda çalıştırmanıza olanak tanır.


#### Nginx konteynerini WordPress konteynerine bağlama

```
location ~ \.php$ {
        try_files $uri =404;
        fastcgi_split_path_info ^(.+\.php)(/.+)$;
        fastcgi_pass wordpress:9000; ----------------> This section is the part that establishes a relationship with the WordPress container
        fastcgi_index index.php;
        include fastcgi_params;
        fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
        fastcgi_param PATH_INFO $fastcgi_path_info;
}
```

`fastcgi_pass` ifadesi, Nginx'in PHP dosyalarını işlenmek üzere bir FastCGI sunucusuna yönlendirmesine olanak tanır. Burada `wordpress:9000`, WordPress'in çalıştığı PHP-FPM (FastCGI Process Manager) sunucusunun adresini ve port numarasını belirtir.
</br> </br>
Bu ifade, içinde `wordpress` adlı bir Docker kapsayıcısının _**port 9000**_ üzerinde çalıştığı `PHP-FPM` sunucusuna erişmek için kullanılır. 
Docker ağı içerisinde çalışan bir konteyneri belirtmek için konteyner adının kullanılması oldukça yaygındır ve Docker bu adı tanır ve doğru IP adresini ve port numarasını ayarlar.
Yani bu ifade sayesinde Nginx, gelen PHP isteklerini doğru FastCGI sunucusuna yönlendirir ve WordPress'in PHP dosyalarını işlemek için bu sunucuya referans verir.
</br> </br>
Özetlemek gerekirse, `fastcgi_pass wordpress:9000` ifadesi, Nginx'in PHP dosyalarını WordPress'in işlenmek üzere çalıştığı PHP-FPM sunucusuna yönlendirmesine olanak tanır, böylece Nginx ile WordPress arasında iletişim kurulur.
</br> </br>
Nginx `sites-available/default` dosyanızdaki `fastcgi_pass wordpress:9000` bölümündeki `wordpress:9000`, WordPress kapsayıcınızın adını ve bağlantı noktası numarasını temsil eder. 
Bu şekilde nginx konteyneriniz WordPress konteynerinize bağlanabilir ve PHP dosyalarını sunabilir.
</br>
Aşağıda bu bölümün nasıl çalıştığına ilişkin daha ayrıntılı bir açıklama bulunmaktadır:
- `fastcgi_pass`: Bu yönerge nginx'e hangi yukarı akış sunucusuna (arka uç) bağlanacağını söyler. Bu durumda yukarı akış sunucusu WordPress kapsayıcınızdır.
- `wordpress`: Bu, yukarı akış sunucusunun adıdır. Docker Compose kullanıyorsanız bu, docker-compose.yml dosyanızda tanımladığınız hizmet adıyla aynı olacaktır.
- `9000`: Bu, yukarı upstream port numarasıdır. Bu, WordPress'in varsayılan port numarasıdır.

Nginx'in WordPress konteynerine nasıl bağlandığının adım adım özeti:
- Nginx bir istek aldığında `location ~ .php$` bloğuna bakar.
- Bu blok, istek bir PHP dosyasıysa (`.php$` ile eşleşir) yürütülür.
- Nginx, `fastcgi_pass` direktifine bakar ve yukarı akış sunucusunun `wordpress:9000` olduğunu görür.
- Nginx, '9000' portunda ki WordPress konteynera bağlanır.
- WordPress kapsayıcısı istenen PHP dosyasını işler ve nginx'e bir yanıt gönderir.
- Nginx yanıtı istemciye gönderir.

Ek olarak:
- `fastcgi_split_path_info` yönergesi URL'yi iki parçaya böler: dosya adı ve yol bilgisi.
-  `fastcgi_index` yönergesi varsayılan dosya adının `index.php` olduğunu belirtir.
- `include fastcgi_params;` Direktif _fastcgi_params_ dosyasındaki tüm parametreleri içerir.
- `fastcgi_param` yönergeler nginx'e ek parametreler göndermenize olanak tanır.

### :thread: WordPress için

#### Mariadb ile wp-config.php irtibatı

`wp-config.php` dosyası _**mariadb kapsayıcısına**_ bağlanabilecek hale getirildiğinde `(define(user, user)` vb. gibi ayarları tanımlayın), mariadb ile bağlantı kurulabilir.
</br>
WordPress'in `wp-config.php` dosyasını yapılandırmak için şu adımları izlemeniz gerekir:
1. **WordPress Konteyner Ağına Erişim:** Öncelikle WordPress konteynerinin ağına erişmeniz gerekir. Bu, Docker Compose veya Docker ağları gibi yöntemlerle gerçekleştirilebilir.
WordPress konteyneri ve MariaDB konteyneri aynı ağda olmalıdır.
2. **Veritabanı Bağlantı Bilgilerinin Belirlenmesi:** WordPress, MariaDB veritabanına bağlanmak için gereken _kullanıcı adı_, _şifre_, _veritabanı adı_ ve _sunucu bilgilerini_ bilmelidir.
Bu bilgiyi sağlayacak şekilde yapılandırmanız gerekecektir.
3. **`wp-config.php` Dosyasını Oluşturma veya Düzenleme:** WordPress kurulumu yaparken veya bir kurulumu yapılandırmak için `wp-config-sample.php` dosyasını `wp-config.php` olarak kopyalayarak başlayabilirsiniz.
Daha sonra bu dosyayı düzenleyerek veritabanı bağlantı bilgilerini eklemelisiniz.

#### `define(DB_HOST, 'mariadb')` bölümü
`DB_HOST` tanımında `mariadb` isminin kullanılmasının nedeni, Docker'da çalışan konteynerler arasında iletişim kurmak için belirli konfigürasyon ve adlandırma standartlarının kullanılmasıdır.
Docker Compose veya Docker ağları gibi araçlarla çalışırken, bir konteyner ağ içinde diğerine isimle ulaşabilir.
</br> </br>
Dolayısıyla MariaDB konteynerinin adı `mariadb` olarak ayarlanırsa WordPress konteynerinin bu adı kullanarak MariaDB veritabanına erişmesi mümkündür.
Yani WordPress, `DB_HOST` tanımındaki `mariadb` adını kullanarak Docker ağında `mariadb` adı altında MariaDB veritabanına erişebilir.
</br> </br>
Ancak Docker ağında farklı bir isimlendirme veya konfigürasyon kullanıyorsanız bu ismi değiştirmeniz gerekebilir.
Örneğin Docker Compose’da farklı bir hizmet adı belirttiyseniz `DB_HOST` değerini buna göre ayarlamanız gerekir.

#### PHP'nin çalışabilmesi için 'php7.4-fpm.pid' isimli bir dosyaya ihtiyaç vardır
`mkdir -p /run/php/;`: Bu komut `/run/php/` dizinini oluşturur. Bu dizin PHP-FPM işlemlerinin PID (İşlem Kimliği) dosyasını içerecektir.
</br> </br>
`touch /run/php/php7.3-fpm.pid;`: Bu komut `/run/php/php7.3-fpm.pid` adında bir PID dosyası oluşturur. Bu dosya PHP-FPM işlem PID'sini içerecektir.
</br> </br>
Bu işlemler yerine bunu doğrudan yapan Dockerfile içerisinde `RUN service php7.4-fpm start` komutunun belirtilmesi yukarıdaki her iki işlemi de gerçekleştirir.
</br> </br>
Bu iki yöntemden biri kullanılabilir. `service php7.4-fpm start` hizmetinin bu şekilde başlatılması `.pid` dosyasını oluşturur veya manuel olarak oluşturulup yapılabilir.

#### "--nodaemonize" nedir?
`--nodaemonize` bayrağı PHP-FPM'nin daemon modunu devre dışı bırakmak için kullanılır. Normalde PHP-FPM başlatıldığında bir daemon olarak çalışır ve arka planda çalışır.
`--nodaemonize` bayrağı PHP-FPM'nin daemon modunu devre dışı bırakarak PHP-FPM'yi önplanda çalıştırmanıza olanak tanır.

#### wp-cli nedir?

**wp-cli** WordPress'i cli'den yüklemek için oluşturulmuş bir komut arayüzüdür.
</br>
Kullanmak için `wp-cli.phar` dosyasını indiriyoruz ve gerekli izinleri verdikten sonra `/usr/local/bin/wp` dizini altına koyuyoruz (wp-cli.phar ismini değiştirerek) komutunu `wp` olarak kullanabilmemiz için.

#### `wp core download` nedir?

`wp core download`, WordPress çekirdek dosyalarını komut (`index.php`, `wp-admin` klasörü vb. gibi).

#### `wp core install` nedir?

Bunu yaparak veritabanımızda (inception_db) bir WordPress tablosu oluşturuyoruz. Bu nedenle, env değişkenlerini kullanırken bunun daha önce MariaDB ile oluşturulan veritabanıyla (inception_db) hiçbir ilgisi yoktur.
Burada WP Core Install'ta parametrelerde verdiğimiz değerlerle WordPress CLI (daha önce MariaDB'de oluşturulmuş inception_db veritabanı) kullanılarak bağlanan veritabanında WordPress için yeni bir tablo oluşturmak istiyoruz.
(yönetici, kullanıcı, mail gibi). Bu nedenle WordPress kurulumunda kullanılmak üzere `.env` dosyasında ayrı env değişkenleri (`WP_ADMIN`, `WP_USER`, vb.) oluşturulur.

### :sewing_needle: MariaDB için

#### MySQL Giriş
```
mysql -u <user_name> -p
```

#### Veritabanlarını, Tabloları ve Kullanıcıları Göster
```
$ SHOW DATABASES;
$ USE <database_name>;
$ SHOW TABLES;

$ SELECT * FROM <table_name>;
$ SELECT user, host FROM mysql.user;
$ SHOW GRANTS FOR 'user_name';
```

#### `expect` Dosyası ve Komutu
'expect' komutu, otomatik görevleri gerçekleştirmek için kullanılan bir Unix ve Linux aracıdır. Genellikle komut dosyalarında kullanılır ve kullanıcıyla etkileşime geçmek için programlar arasında bir köprü görevi görür.
Özellikle etkileşimli olmayan süreçleri otomatikleştirmek veya test senaryoları oluşturmak için sıklıkla kullanılır.
</br></br>
Bir `expect` betiği bir veya daha fazla beklenen sonucu (istem, çıktı vb.) belirler ve bu sonuçlara göre belirli eylemleri gerçekleştirir. 
Örneğin bir SSH oturumuna otomatik olarak bağlanmak, bir komutu uzaktan yürütmek ve ardından çıktısını kontrol etmek gibi görevleri gerçekleştirebilir.
</br></br>
`.expect` dosyaları, genellikle `expect` komutu kullanılarak oluşturulan beklenen sonuçları içerir. Bu dosyalar belirli bir işlemi otomatikleştirmek veya test senaryoları oluşturmak için kullanılır.
Örneğin, kullanıcı adı ve parola isteyen bir oturum açma ekranıyla etkileşim kurarak oturumu otomatik olarak başlatmak için bir `.expect` dosyası oluşturabilirsiniz.
```
expect "Username:"
send "my_username\r"
expect "Password:"
send "my_password\r"
expect eof
```
Bu örnek bir oturuma otomatik olarak giriş yapmak için kullanılabilir. Önce `Kullanıcı adı:` yazısını bekler, sonra kullanıcı adını gönderir, ardından `Şifre:` yazıp şifreyi gönderir, 
ve son olarak işlemi sonlandırır (eof: dosya sonu).
</br></br>
Bu dosyaları çalıştırmak için genellikle `wait` komutu kullanılır ve `.expect` dosya adı argüman olarak verilir:
```
expect my_script.expect
```
Bu komut, my_script.expect adlı `.expect` dosyasını çalıştırır ve beklenen sonuçlara göre belirtilen işlemleri gerçekleştirir.
</br></br>
Özetle, `expect` komutu, otomatikleştirilmiş görevleri gerçekleştirmek için kullanılan bir araçtır ve .expect dosyaları, bu görevleri otomatikleştirmek veya test senaryoları oluşturmak için kullanılan dosyalardır.

**🏁Ve nihayet kısım 3 burada bitiyor..🏁**

## :four: Kısım 4 - ~ B O N U S ~

### :plunger: Adminer için

Yönetici, veritabanı tablolarının tarayıcı aracılığıyla görüntülenmesine ve yönetilmesine olanak sağlayan bir araçtır.

#### Giriş yapmak için gerekli bilgiler

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Inception/imgs/adminer-login.png" align="center" height="800">

Servislere ağ üzerinden eriştiğimiz ve konteyner isimleri üzerinden eriştiğimiz için konteyner ismimizi `Server` yazan yere `mariadb` yazacağız.
Daha sonra MariaDB kurulumunda ilk kez oluşturduğumuz `DB_USER` ve `DB_USER_PASS` ile kullanıcı bilgilerini girip, `DB_NAME` ile veritabanı ismimizi belirterek tabloları görüntüleyebiliriz.

### :placard: Website için

Node.js uygulaması oluşturma, Node.js kullanarak bir yazılım projesinin başlatılması ve geliştirilmesi sürecidir. Node.js, JavaScript tabanlı arka uç uygulamaları oluşturmak için kullanılan bir çalışma zamanı ortamıdır.
</br> </br>
Node.js uygulaması oluşturma sürecinin genel adımları şunlardır:
1. **Node.js Kurulumu:** İlk adım olarak Node.js'nin en son sürümünü bilgisayarınıza yüklemeniz gerekir. Node.js'yi resmi web sitesinden indirip yükleyebilirsiniz.
2. **Proje Dizini Oluşturma:** Node.js projesi oluşturmak için bir klasör oluşturun ve bu klasöre gidin.
3. **`package.json` Dosyasını Oluşturma:** Node.js projeleri genellikle package.json dosyasıyla başlar. Bu dosya proje bağımlılıklarını ve projeyle ilgili temel bilgileri içerir.
`npm init` komutunu kullanarak bir `package.json` dosyası oluşturabilirsiniz. İlgili bilgiler girildikten sonra bu dosya oluşturulur..
4. **Gerekli Modüllerin Kurulumu:** Projenizin ihtiyaç duyduğu modülleri `npm install` komutuyla kurun. Bu komut bağımlılıkları otomatik olarak `package.json` dosyasına yükler.
5. **Ana Uygulama Dosyasını Oluşturma:** Node.js uygulamanızın ana dosyasını oluşturun. Bu dosyaya genellikle `index.js` veya `app.js` adı verilir.
6. **Uygulamayı Başlatma:** Node.js uygulamanızı başlatmak için terminaldeki proje dizinine gidin ve ana dosyanızı çalıştırın. Örneğin, `node index.js` veya `node app.js` gibi bir komut kullanılabilir.

### :fire_extinguisher: Redis için

#### Redis eklentisini yükleme ve etkinleştirme

WordPress hizmetinin dizinindeki `wp-setup.sh` dosyasında WordPress kurulumu sonrasında redis eklentisi için eklenen satırlar:
```
wp plugin install redis-cache --activate --allow-root
wp redis enable --allow-root
```

#### Bağlamak için 'redis.conf'
`Bind 127.0.0.1 ::1` ayarının yorumlanması, Redis sunucusunu yalnızca yerel bağlantılara (127.0.0.1) bağlanmaktan tüm ağ bağlantılarına (0.0.0.0) bağlanmaya izin verecek şekilde değiştirir.
Bu değişiklik Redis'in varsayılan olarak yalnızca localhost'a (127.0.0.1) bağlanmasını engeller ve Redis'in diğer IP adreslerinden gelen bağlantıları kabul etmesine olanak tanır.
</br></br>
Reasons:
- **Uzak bağlantılara izin ver:** Redis sunucunuzun uzaktan erişilebilir olmasını istiyorsanız yani farklı IP adreslerinden gelen bağlantıları kabul etmesini istiyorsanız bu değişikliği yapabilirsiniz.
- **Küme yapılandırması:** Redis'i küme olarak yapılandırıyorsanız ve farklı sunucular arasında iletişim kurmak istiyorsanız bu değişikliği yapmanız gerekebilir.
- **Docker ve Kubernetes gibi platformlar:** Redis konteynerlerini Docker veya Kubernetes gibi platformlarda çalıştırıyorsanız, bu platformlar genellikle farklı IP adreslerinden gelen bağlantıları kabul etmek için bu tür yapılandırmalara ihtiyaç duyar.

Ancak bu değişikliği yaparken güvenlik risklerini dikkate almak önemlidir. Redis sunucunuz internete açık bir ortamda çalışıyorsa güvenlik önlemlerini almalı ve gelen bağlantıları sınırlandırmalısınız.
Aksi takdirde güvenlik açıklarından veya kötü niyetli kullanıcılar tarafından istismar edilebilir.

#### Wordpress hizmetindeki `wp-config.php` dosyasındaki Redis ayarları
- `define( 'WP_REDIS_HOST', 'redis' );`   --> Redis hizmetinin kapsayıcı adı 'redis' anlamına geldiğinden ve WordPress'in bağlanması gerektiğinden bu adı veriyoruz.
- `define( 'WP_REDIS_PORT', 6379 );`      --> Redis hizmetinin çalıştığı port numarasını veriyoruz.
- `define('WP_CACHE', true);`             --> WordPress'in önbelleğe almayı etkinleştirip etkinleştirmediğini belirler.


#### Redis'in kurulu olduğunu doğrulama
Redis'in WordPress'e başarıyla bağlandığını doğrulamanın birkaç yolu vardır:
WordPress yönetici panelinde Redis eklentisi: WordPress sitenizde Redis için bir eklenti kullanıyorsanız genellikle bu eklentinin yönetici panelinde Redis bağlantısı ile ilgili bilgileri görebilirsiniz.. 
Bu bilgiler genellikle Redis sunucunuzun IP adresini, bağlantı portunu ve diğer yapılandırma ayarlarını içerir.
</br></br>
_**Yönetici panelindeki _**sol taraftaki panelden**_ `https://localhost:443/wp-admin`, yani `eklentiler->yüklü eklentiler->Redis Nesne Önbelleği->ayarlar'a tıklayın **_ ve bağlı olduğunu görün.


### :sponge: FTP Server için

#### FTP-Server nedir?

Bir daemon olması ve aynı zamanda uzak bağlantılar için bir sunucu olması nedeniyle `sshd` gibi düşünülebilir. Gerekli port konfigürasyonları, root olarak bağlanıp bağlanamayacağı vb.
Uzaktan bağlanacak cihazlar için `sshd.config` dosyasından işlemleri kural haline getirebildiğimiz gibi, ftp sunucusunun da bir daemon'u (vsftpd) ve bir config dosyası vardır.
Bununla kullanıcı izinlerini, dosya izinlerini vb. değiştirebilirsiniz. İşlemleri vardır. `vsftpd` ftp sunucusu için örnek bir uygulamadır. Elbette ssh (telnet) dışında alternatifleri de mevcut.

SSH (Secure Shell) sunucusu (sshd), uzaktan erişim ve yönetim için güvenli bir araç sağlar. Benzer şekilde vsftpd (Çok Güvenli FTP Programı) bir FTP sunucusudur ve dosya aktarımı için merkezi bir sunucu görevi görür.

Her ikisi de aynı mantıkla çalışır:
- **sshd:** SSH sunucusu uzaktan erişim ve yönetim sağlar. Bu sunucu uzak cihazlara bağlanmak ve komutları çalıştırmak için bir arayüz sağlar. Dosya aktarımı SSH üzerinden de güvenli bir şekilde yapılabilmektedir.
- **vsftpd:** FTP sunucusu dosya aktarımı için merkezi bir sunucu görevi görür. Bu sunucu dosyaları saklar ve kullanıcılara bu dosyalara erişim sağlar.
FTP sunucusu, dosyaları belirli bir dizinde saklar ve istemcilere bu dizindeki dosyaları görüntüleme ve değiştirme izni verir.

Her ikisi de aynı amaca hizmet eder, ancak farklı protokoller kullanır: Uzaktan erişim ve komut yürütme için SSH kullanılırken, dosya aktarımı için FTP kullanılır.
Ancak her ikisi de uzak cihazlar arasında dosya aktarımını ve yönetimini etkinleştirmek için kullanılabilir.
</br> </br>

vsftpd (Çok Güvenli FTP Daemon'u) aslında bir FTP sunucu programıdır ve FTP protokolünü destekleyen istemcilerin (FileZilla gibi) sunucuya bağlanmasına olanak tanır. 
vsftpd, dosya aktarımı için merkezi bir sunucu görevi görür ve istemcilere dosyalara erişim sağlar. İstemciler vsftpd sunucusuna bağlanarak dosyaları indirebilir, 
yükleyebilir veya yönetebilir. Yani vsftpd bir sunucu programıdır ve FTP istemcileri (FileZilla gibi) tarafından kullanılır.

#### FTP sunucusu için gerekli konfigürasyonları yaptıktan sonra FileZilla kullanarak test ediniz

FileZilla bir FTP istemcisidir ve başka bir cihaza bağlanmak için bu cihazın bir FTP sunucusu olarak yapılandırılması gerekir. Bağlanmak istediğiniz cihazın bir FTP sunucusu olarak çalışması ve ona erişim izinlerinin olması gerekir:
- **FTP Sunucusunu Yapılandırma:** Bağlanmak istediğiniz cihazın bir FTP sunucusu olarak çalışması gerekir. Bu sunucu dosyaları saklar ve istemcilere erişim sağlar. Sunucunun bir FTP sunucusu olarak yapılandırıldığından emin olun.
- **FTP Sunucusuna Bağlantı Bilgileri:** Bağlanmak istediğiniz cihazın FTP sunucusuna erişim için gerekli olan IP adresi, kullanıcı adı ve şifre gibi bilgilere ihtiyacınız olacaktır.
Bu bilgiler sunucunun yöneticisi veya sahibi tarafından sağlanmalıdır.
- **FileZilla İstemcisini Kullanma:** Bağlanmak istediğiniz cihazın FTP sunucusuna erişmek için FileZilla istemcisini kullanabilirsiniz. FileZilla'yı açın ve bağlanmak istediğiniz sunucunun IP adresini, kullanıcı adını ve şifresini girin.
- **Bağlantı Kurma:** FileZilla, sağladığınız bilgilere göre sunucuya bağlanacak ve sunucunun dosya sistemi içeriğini gösterecektir. Bağlantı kurulduktan sonra dosyaları indirebilir, yükleyebilir veya yönetebilirsiniz.

Yukarıdaki adımları izleyerek başka bir cihaza bağlanabilir ve FileZilla veya başka bir FTP istemcisini kullanarak dosyalarına erişebilirsiniz. Ancak bağlanmak istediğiniz cihazın şu şekilde yapılandırıldığından emin olun:
FTP sunucusu ve erişim izinlerine sahiptir. Doğru şekilde ayarlandığından emin olmak önemlidir.

#### FileZilla `Hata: Dizin listesi alınamadı.'

GUI ftp istemcilerindeki Pasif modda bir sorun olduğu düşünülüyor.
</br></br>
`vsftpd.conf` dosyasında `listen=NO`'yu `listen=YES` ve `listen_ipv6=YES`'i `listen_ipv6=NO` olarak değiştirdiğimde sorun çözüldü.
</br></br>
Sorunun `pasv_address` ile ilgili olduğunu düşünüyorum. FileZilla'da Host bölümüne ne yazıyorsa `pasv_address` değerine yazmalısınız.
</br></br>
Vbox'ta Ağ ayarım olarak `köprü bağdaştırıcısı` ile çalıştığım için yönlendirici sanal makineme IP atıyor, dolayısıyla atanan değeri `pasv_address` değerine yazıyorum. 
Ancak, Vbox Ağ ayarıyla çalışan bir sanal makine için `NAT`, `127.0.0.1` veya localhost'un muhtemelen `pasv_address` değerine yazılması gerekecektir.
Bunu söylemek için temel noktam, Vbox'taki ağ ayarımın `köprü bağdaştırıcısı` olması, bu yüzden bana atanan IP'yi (192.168.1.27) `pasv_address` değerine yazıyorum.
Dizinim hata alınmadan listelendi. Ancak, Vbox ağ ayarım `köprü bağdaştırıcısı` olduğunda ve `127.0.0.1` IP'sini `pasv_address` değerine atadığımda ne yazık ki şunu alıyorum: 
`Hata: Dizin listesi alınamadı.` Hatasını aldım. Sorun muhtemelen bununla alakalıdır.

#### Sunucuya FTP komutuyla bağlanma
FileZilla ile ilgili bir sorun varsa alternatif yöntem olarak `ftp` komutunu kullanabiliriz:
```
ftp <server-ip>
```
ya da
```
ftp <user_name>@<server-ip>
```
`kullanıcı_adı` ftp sunucusu için oluşturulan kullanıcıdır. Daha sonra ftp sunucusu için oluşturduğumuz _**kullanıcı adı**_ ve _**şifre**_ sorulacak ve bunları girmeniz gerekmektedir. </br></br>
Daha sonra normal Linux komutlarından bazılarını (ls, pwd vb.) kullanabiliriz. Bunu help'e tıklayarak görebilirsiniz.
Sunucudan dosya çekmek için `get <file_name>` diyerek, sunucuya dosya yüklemek için `put <file_name>` diyerek sunucuya dosya yükleyebilirsiniz.

#### [İsteğe bağlı] Sftp sunucusu ve `sftp` komutunu kullanma hakkında
SFTP, Güvenli Dosya Aktarım Protokolü veya SSH Dosya Aktarım Protokolü'nün kısaltmasıdır. Güvenli Dosya Aktarım Protokolü anlamına gelir. SSH (Secure Shell) protokolü üzerinden dosya aktarımına olanak sağlayan bir ağ protokolüdür.
SSH altyapısını kullanır.
</br></br>
FileZilla ile test yaparken bu protokol SSH'nin bir alt kümesi olduğundan porta _**22**_ veya belirtilen port numarası yazılmalıdır.
</br></br>
**`sftp` komut kullanımı:**
```
sftp <user_name@server_ip>
```
Bağlandıktan sonra, ftp komutuyla bağlandıktan sonra kullandığınız `get`, `put` vb. komutların aynısını kullanın.
</br></br>
`kullanıcı_adı` sftp sunucusu için oluşturulan kullanıcıdır.

#### Sftp _known hosts_ problemi

```
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@    WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED!     @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
IT IS POSSIBLE THAT SOMEONE IS DOING SOMETHING NASTY!
Someone could be eavesdropping on you right now (man-in-the-middle attack)!
It is also possible that a host key has just been changed.
The fingerprint for the ED125gw1 key sent by the remote host is
SHA256:a12dsc24gvss24tnsxffkymgdi215m2dsc25622ccb1scsu32fsdas42g3fdd.
Please contact your system administrator.
Add correct host key in /home/ftekdrmi/.ssh/known_hosts to get rid of this message.
Offending ECDSA key in /home/ftekdrmi/.ssh/known_hosts:2
  remove with:
  ssh-keygen -f "/home/ftekdrmi/.ssh/known_hosts" -R "192.168.1.27"
Host key for 192.168.1.27 has changed and you have requested strict checking.
Host key verification failed.
Connection closed
```

SSH bağlantılarında zaman zaman yaşanan bu sorunun çözümü zaten içeride yazılı.


#### sftp `put` Problem

"`/var/www` izni, chroot'lu kullanıcının burada dosya oluşturmasına izin vermiyor.
Bu doğrudur ve tasarım gereğidir.
`/var/www` içinde kullanıcının uygun haklarına sahip bir klasör oluşturmalısınız.

`/var/www` can not be writeable for the user."

Söylentiler bu yöndeydi ama daha ileri gitmedim. Eğer daha fazla hata yapsaydım gözyaşlarına boğulacaktım o yüzden sorunu yapmadım ama tabi ki bunun da bir çözümü olabilir.

### :window: Kendi Servisiniz

Liman konteynerinde Windows hizmetini çalıştırmayı seçtim. Bu yüce ve kadim gücün keşfedilmesi gerekiyordu.

#### Önkoşullar

Bu hizmeti kullanabilmek için öncelikle ön konfigürasyon ve indirmeler yapmamız gerekmektedir. Windows, KVM hipervizörü sayesinde docker konteynerinde çalışabilir. 
Bunu docker konteynerine verdiği `--device=/dev/kvm` parametresi sayesinde yapabilir. Bu parametre, konteynerin ana makinedeki `kvm` cihazına erişmesine izin verir.
Bu yüzden öncelikle sanal makinemize kvm kurmamız gerekiyor.

Yapılması gereken iki adım var;

1. **Kvm'yi yükleme ve yapılandırma::**
```
$ sudo apt update && sudo apt install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils virt-manager -y
$ usermod -aG libvirt $(whoami)
$ sudo systemctl start libvirtd
$ sudo systemctl enable libvirtd
$ sudo modprobe kvm
$ sudo nano /etc/modules
```
`/etc/modules` dosyasının içeriği şu şekilde görünmelidir:
```
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
# /etc/modules: kernel modules to load at boot time.
#
# This file contains the names of kernel modules that should be loaded
# at boot time, one per line. Lines beginning with "#" are ignored.

kvm
kvm_intel
kvm_amd
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
```
Kvm'nin yolunu kontrol edin:
```
lsmod | grep kvm
```
KVM başarıyla kurulduysa `/dev/kvm` dizini oluşturulmuş olmalıdır.
Bu dizin, KVM sanallaştırması için gerekli olan bir aygıt dosyasıdır ve KVM sanal makinelerinin ana makine ile iletişim kurmasını sağlar.

2. **VirtualBox veya sanallaştırma programında _**yuvalanmış sanallaştırma**_ özelliğini etkinleştirme:**
VirtualBox'ta sanal makinenin ayarlarında CPU'yu ayarladığımız bölümde _**Enable Nested VT-x/AMD-V**_ seçeneği mevcut ancak bu bölüm seçilemiyor.
Bu yüzden bu ayarı oradan etkinleştiremeyeceğimiz için `VBox` komut arayüzünü kullanmak zorunda kalacağız.

_Linux Vbox'ta **yuvalanmış sanallaştırma** özelliğinin etkinleştirilmesi:_
Sanal makinemde Debian kurulu olduğu için Vbox'ın cli'sini kullanarak aşağıdakileri yapmam gerekiyor. </br>
Sanal makineleri listelemek ve adlarını görmek için:
```
vboxmanage list vms
```
İlgili sanal makinenin _nested virtualize_ özelliğini etkinleştirmek için:
```
VBoxManage modifyvm "<relevant_virtual_machine_name>" --nested-hw-virt=on
```
- _Windows Vbox'ta **iç içe sanallaştırma** özelliğini etkinleştirme_
Windows sisteminizde VirtualBox'ın kurulu olduğu dizine gidin ve orada `VBoxManage.exe` dosyasını bulun ve bulduğunuz dizini kopyalayın.
Kopyalanan dizin şuna benzer: `C:\Program Files\Oracle\Virtual Box`. </br>

Daha sonra _Komut İstemi_'ni açın ve yazın (Dizininiz farklı olabilir):
```
cd C:\Program Files\Oracle\Virtual Box
```
Daha sonra yaz:
```
VBoxManage modifyvm <relevant_virtual_machine_name> --nested-hw-virt on
```
Daha sonra gerekli ayarlarda etkinleştirilip etkinleştirilmediğini onaylayın. </br> </br>
Yuvalanmış bir sanal makine olacağından ekstra işlemci çekirdekleri sağlamak ve belki de _**PAE/NX'i Etkinleştir**_ özelliğini etkinleştirmek faydalı olabilir. ardından sanal makineyi _**yeniden başlatın**_

#### Windows Sürümünü Değiştir

Windows sürümü docker dosyasında ki `VERSION` çevre değişkeninden değiştirilebilir:

| **Value**  | **Description**  | **Source**  | **Transfer**  | **Size**  |
|---|---|---|---|---|
| `win11`   | Windows 11 Pro         | Microsoft    | Fast    | 6.4 GB    |
| `win10`   | Windows 10 Pro         | Microsoft    | Fast    | 5.8 GB    |
| `ltsc10`  | Windows 10 LTSC        | Microsoft    | Fast    | 4.6 GB    |
| `win81`   | Windows 8.1 Pro        | Microsoft    | Fast    | 4.2 GB    |
| `win7`    | Windows 7 SP1          | Bob Pony     | Medium  | 3.0 GB    |
| `vista`   | Windows Vista SP2      | Bob Pony     | Medium  | 3.6 GB    |
| `winxp`   | Windows XP SP3         | Bob Pony     | Medium  | 0.6 GB    |
||||||
| `2022`    | Windows Server 2022    | Microsoft    | Fast    | 4.7 GB    |
| `2019`    | Windows Server 2019    | Microsoft    | Fast    | 5.3 GB    |
| `2016`    | Windows Server 2016    | Microsoft    | Fast    | 6.5 GB    |
| `2012`    | Windows Server 2012 R2 | Microsoft    | Fast    | 4.3 GB    |
| `2008`    | Windows Server 2008 R2 | Microsoft    | Fast    | 3.0 GB    |
||||||
| `core11`  | Tiny 11 Core           | Archive.org  | Slow    | 2.1 GB    |
| `tiny11`  | Tiny 11                | Archive.org  | Slow    | 3.8 GB    |
| `tiny10`  | Tiny 10                | Archive.org  | Slow    | 3.6 GB    |


#### Çalıştır
Çalıştırmak için tarayıcı URL'sine `IP:8006` bağlantı noktasını yazdığınızda, noVNC sayesinde docker kapsayıcısında çalışan pencereler tarayıcı aracılığıyla açılacaktır.


### :paintbrush: QEMU Servisi için

Windows servisi qemu servisi sayesinde çalışabildiği için onu da derlememiz gerekiyor o yüzden servisler arasında yer alıyor.

#### Qemu Desteği
Qemu dosyalarının kapsayıcıya dahil edildiği Windows docker dosyasında ki satır:
```
COPY --from=qemu:not-latest / /
```
#### Debian _trixie-slim_ sürümü
Qemu docker dosyasında daha minimal içerik sunan ve debian 11 sürümünü temel alan _trixie-slim debian version_ kullanılıyor.

**🏁Ve nihayet Kısım 4 burada bitiyor..🏁**

## :paperclip: Kaynaklar

### VS Code
1. [VSCode Remote SSH Connection Failed](https://stackoverflow.com/questions/60507713/vscode-remote-ssh-connection-failed)
2. [VS Code Remote SSH Connection not working](https://stackoverflow.com/questions/64034813/vs-code-remote-ssh-connection-not-working)

### Docker Essentials
1. [Github Forstman1](https://github.com/Forstman1/inception-42?tab=readme-ov-file)
2. [Github Codesshaman](https://github.com/codesshaman/inception/tree/main)
3. [Github Vbachele](https://github.com/vbachele/Inception?tab=readme-ov-file)
4. [Github Gkandemi](https://github.com/gkandemi/docker)
5. [Docker Nedir Nasıl Kullanılır? | Part #1 | Image Nedir? Container Nedir? Docker Komutları](https://www.youtube.com/watch?v=4XVfmGE1F_w&list=PL_f2F0Oyaj4_xkCDqnRWp4p5ypjDeC0kO&index=1)
6. [The Ultimate Docker Cheat Sheet](https://dockerlabs.collabnix.com/docker/cheatsheet/#image-management-commands)
6. [Learn Docker in 7 Easy Steps - Full Beginner's Tutorial](https://www.youtube.com/watch?v=gAkwW2tuIqE)
6. [Docker Basics Tutorial with Node.js](https://fireship.io/lessons/docker-basics-tutorial-nodejs/)
6. [Github Fireship](https://github.com/fireship-io/docker-nodejs-basic-demo)
6. [Github farukdll](https://github.com/farukdll/Docker/tree/main?tab=readme-ov-file)
6. [Medium iremsalgar](https://medium.com/@iremsalgar/docker-42-c649c4e2e1ca)
6. [Docker Compose Env File - How to Read in environment variables file ( Docker )](https://www.youtube.com/watch?v=1je3VxDF67o)
6. [Difference Between run, cmd and entrypoint in a Dockerfile](https://www.baeldung.com/ops/dockerfile-run-cmd-entrypoint)

### Nginx
1. [Installing a Basic SSL/TLS Certificate in nginx](https://www.youtube.com/watch?v=xNk8fZCuCMU)
1. [How to Set Up SSL with NGINX](https://www.youtube.com/watch?v=X3Pr5VATOyA&t=65s)
1. [Error code: ssl_error_rx_record_too_long on nginx ubuntu server](https://stackoverflow.com/questions/25081239/error-code-ssl-error-rx-record-too-long-on-nginx-ubuntu-server)

### WordPress
1. [Github Fartomy PHP](https://github.com/Fartomy/42-Kickoff/tree/master/Born2beroot/debian#%EF%B8%8F-for-php)
2. [Github Fartomy Wordpress](https://github.com/Fartomy/42-Kickoff/tree/master/Born2beroot/debian#-for-wordpress)
2. [Installing WP-CLI](https://make.wordpress.org/cli/handbook/guides/installing/)
2. [WP Core Install](https://developer.wordpress.org/cli/commands/core/install/)
2. [WP User Create](https://developer.wordpress.org/cli/commands/user/create/)
2. [wp-config.php Configuration](https://developer.wordpress.org/apis/wp-config-php/)
2. [Wordpress Theme Setup](https://wordpress.com/themes/free)

### MariaDB
1. [Github Fartomy MariaDB](https://github.com/Fartomy/42-Kickoff/tree/master/Born2beroot/debian#-for-mariadb)

#### B O N U S

##### Adminer
1. [How to install Adminer (Database Administration Tool) on Ubuntu 22.04 | VPS Tutorial](https://www.youtube.com/watch?v=r4keak825B4)
1. [How to start apache2 automatically in a ubuntu docker container?](https://stackoverflow.com/questions/44376852/how-to-start-apache2-automatically-in-a-ubuntu-docker-container#44377561)
1. [Github CodeShaman](https://github.com/codesshaman/inception/blob/main/12_INSTALL_ADMINER.md)
1. [How to configure Adminer to be reachable on the local network](https://askubuntu.com/questions/813282/how-to-configure-adminer-to-be-reachable-on-the-local-network)
1. [How to Setup MariaDB + Adminer with Docker Compose ( Docker )](https://www.youtube.com/watch?v=uAH2zCYzhNw)

##### Website
1. [Creating a static website using Node.Js](https://www.youtube.com/watch?v=894__EP1wks)
1. [Create Static Webpages With Node Express.js](https://www.youtube.com/watch?v=iHAywmmHIV0)
1. [npm-init create a package.json file](https://docs.npmjs.com/cli/v6/commands/npm-init)

##### Redis
1. [How to Install and Configure Redis for WordPress](https://www.youtube.com/watch?v=jZo97S85gWE)

##### FTP-Server
1. [How to install an FTP Server on Ubuntu 22.04 with VSFTPD](https://www.youtube.com/watch?v=XNjOSY-wcb0)
1. [(How To) Install FTP Server (VSFTPD) on Ubuntu 20.04 (2020) #1](https://www.youtube.com/watch?v=1WVBC0KBOeE)
1. [How to Install and Set Up SFTP Server in Ubuntu 22.04](https://www.youtube.com/watch?v=pS_mY4Rfsg8)
    - [Create SFTP user and allow access to specific directory | SFTP Chroot](https://www.youtube.com/watch?v=XhnqJ4S7C10)
1. [How To Install an FTP Server in Ubuntu with VSFTPD](https://www.youtube.com/watch?v=k3Z_dqe0PzY)
1. [How to Setup FTP server in Ubuntu 22.04 using VSFTPD (2024)](https://www.youtube.com/watch?v=S5kDfUVXsw0)
1. [How to automatically add user account AND password with a Bash script?](https://stackoverflow.com/questions/2150882/how-to-automatically-add-user-account-and-password-with-a-bash-script#7701319)
1. [Run adduser non-interactively](https://askubuntu.com/questions/94060/run-adduser-non-interactively#94067)
1. [Easily Move Files To and From a Server with VSFTP | Top Docs with Jay LaCroix](https://www.youtube.com/watch?v=t50UfbGvWhw)
**About Errors:**
1. [vsftpd error Listing Directories](https://stackoverflow.com/questions/4723023/vsftpd-error-listing-directories)
2. [VSFTP failed to retrieve directory listing](https://askubuntu.com/questions/983065/vsftp-failed-to-retrieve-directory-listing)
2. [VSFTP failed to retrieve directory listing](https://serverfault.com/questions/555541/failed-to-retrieve-directory-listing-in-filezilla-connecting-to-vsftpd)
2. [SOLVED vsftpd Error: Failed to retrieve directory listing](https://www.linuxquestions.org/questions/linux-server-73/vsftpd-error-failed-to-retrieve-directory-listing-878838/)
2. [vsftpd does not list content of a directory](https://unix.stackexchange.com/questions/30559/vsftpd-does-not-list-content-of-a-directory)
2. [227 Entering Passive Mode (0,0,0,0,...) when connecting to vsftpd FTP server](https://superuser.com/questions/1502015/227-entering-passive-mode-0-0-0-0-when-connecting-to-vsftpd-ftp-server)
2. [Ubuntu: Trying to connect to vsftpd, Failed to retrieve directory listing (2 Solutions!!)](https://www.youtube.com/watch?v=RxRJgNxNjPk)
2. [FileZilla Server: Failed to Retreive Directory Listing FIX](https://www.youtube.com/watch?v=faDFDOK02-0)
2. [How to Fix Failed to Retrieve Directory Listing Error in FileZilla FTP? | MilesWeb](https://www.youtube.com/watch?v=HeHfmLSj7ik)
**About SFTP:**
1. [How to use SFTP Commands to Copy Files to/from a Server](https://www.youtube.com/watch?v=22lBJIfO9qQ)
1. [SFTP Error: open for write: permission denied](https://serverfault.com/questions/672755/sftp-error-open-for-write-permission-denied)

##### Own Service
1. [Running Windows in a Docker Container!](https://www.youtube.com/watch?v=xhGYobuG508)
1. [Microsoft Remote Desktop](https://apps.microsoft.com/detail/9wzdncrfj3ps?hl=en-us&gl=US)
1. [Github Dockur Windows](https://github.com/dockur/windows/tree/master)
1. [Github Dockur Windows Version List](https://github.com/dockur/windows?tab=readme-ov-file#faq)
1. [How to Install KVM and Configure Bridge Network in Debian12 | Ubuntu 22.04](https://www.youtube.com/watch?v=KFVe0-B2yLI)
1. [A VM inside a VM inside a VM - Nested Virtualized Explained!](https://www.youtube.com/watch?v=sieDrofaaDU)
1. [Enable Nested VT-x/AMD-V Greyed Out On Virtualbox | How To enable nested VTx/AMD V](https://www.youtube.com/watch?v=nI1gKNGKDws)
1. [How to enable nested VTX/Amd-V On Virtualbox | Virtualbox enable nested vtx/amd-v greyed out](https://www.youtube.com/watch?v=yp9CFQhEaUg)
1. [How to: "Enable Nested VT-x/AMD-V" on Virtualbox, UBUNTU OS](https://www.youtube.com/watch?v=pw49GqTMdIo)
1. [VirtualBox nested Intel virtualization is here!](https://www.youtube.com/watch?v=JMT2qimIL9Q)
1. [VirtualBox Nested Virtualization with VMware ESXi](https://www.youtube.com/watch?v=fWP0ii7gysg)

</br></br>

🏁Ve son olarak README.md burada bitiyor..🏁

<img src="https://github.com/Fartomy/42-Kickoff/blob/master/Inception/imgs/googledream.jpg" align="center">
