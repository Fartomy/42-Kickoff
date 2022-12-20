# Colors
RESET	= \033[0m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m
RED		= \033[31m

# Vars
DATA	= /home/ftekdrmi/data
DATA_DB = /home/ftekdrmi/data/datab_vol
DATA_WP = /home/ftekdrmi/data/wordpr_vol
YML_FILE = ./srcs/docker-compose.yml

# Onemli Notlar
# 1- fclean komutunu - sudo make fclean - diyerek yap, normali 'Permission denied' veriyor.
# 2- .yml dosyasi ayaga kalktiginda database'e hemen baglanamadigindan hata verebilir. 3 - 5 dk bekleyip oyle baglanmayi dene localhost'a. 

all: data datab_vol wordpr_vol dc_up

dc_up:
	@echo "$(GREEN)>- Getting up.. $(RESET)"
	@docker-compose -f $(YML_FILE) up -d

dc_down:
	@echo "$(YELLOW)>- Calm down.. $(RESET)"
	@docker-compose -f $(YML_FILE) stop
	@echo "$(BLUE)>- It's Calm down. $(RESET)"

data:
		@echo "$(YELLOW)>- Creating Volume Files.. $(RESET)"
		@mkdir $(DATA)

datab_vol:
			@mkdir $(DATA_DB)

wordpr_vol:
			@mkdir $(DATA_WP)

clean: dc_down
		@echo "$(RED)>- Erasing Data Files.. $(RESET)"
		@rm -rf $(DATA)

fclean: clean clr_ntw clr_img clr_vlm clr_cnt

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