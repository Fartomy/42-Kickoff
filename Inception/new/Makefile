# Onemli Notlar
# 1- fclean komutunu - sudo make fclean - diyerek yap, normali 'Permission denied' veriyor. 
# "/home/$(USER)/data" silinmiyor manuel olarak elle silmek gerek buna cozum bul.
# 2- .yml dosyasi ayaga kalktiginda database'e hemen baglanamadigindan hata verebilir. 3 - 5 dk bekleyip oyle baglanmayi dene localhost'a. 

# Colors
RESET	= \033[0m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m
RED		= \033[31m

# Vars
DATA	= /home/$(USER)/data
DATA_DB = /home/$(USER)/data/mariadb
DATA_WP = /home/$(USER)/data/wordpress
YML_FILE = ./srcs/docker-compose.yml

all: data dc_up

dc_up:
	@echo "$(BLUE)>- Getting up.. $(RESET)"
	@docker-compose -f $(YML_FILE) up -d

dc_down:
	@echo "$(YELLOW)>- Calm down.. $(RESET)"
	@docker-compose -f $(YML_FILE) stop
	@echo "$(BLUE)>- It's Calm down. $(RESET)"

data:
	@mkdir $(DATA) && mkdir $(DATA_DB) && mkdir $(DATA_WP)
	@echo "$(GREEN)>- The [$(DATA)] Path Created! $(RESET)"

clean: dc_down
	@sudo rm -rf /home/$(USER)/data/
	@echo "$(RED)>- Everything Deleted! $(RESET)"

fclean: dc_down clr_ntw clr_img clr_vlm clr_cnt clean

re: fclean all

clr_img:
		@echo "$(RED)>- Erasing Images.. $(RESET)"
		@docker system prune -a -f

clr_ntw:
		@echo "$(RED)>- Erasing Networks.. $(RESET)"
		@docker network prune -f

clr_vlm:
		@echo "$(RED)>- Erasing Volumes.. $(RESET)"
		@docker volume rm $$(docker volume ls -q)

clr_cnt:
		@echo "$(RED)>- Erasing Containers.. $(RESET)"
		@docker container prune -f

.PHONY: dc_up dc_down clr_cnt clr_img clr_vlm clr_ntw fclean clean