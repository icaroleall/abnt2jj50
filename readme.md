# JJ50 "ABNT"

![jj50](https://user-images.githubusercontent.com/74465757/197259615-6e01b139-9600-47b6-8d34-4fa16c3fe1ef.jpg)
Esse projeto é baseado na minha necessidade de usar o teclado tanto para digitação quanto para escrita de código, e eu não queria reaprender a digitar todas as acentuações e ç durante o uso fora dos editores de código. No meu uso, quando estou digitando textos utilizo o idioma de entrada PT-BR e escrevendo código utilizo o padrão EN-US. Isso explica o Tap-dance na minha tecla OS, para que eu possa modificar o idioma com mais naturalidade(o atalho do sistema operacional (tanto no win quanto no Ubuntu) para a troca do idioma (OS + espaço) também é simples e até mesmo um pouco mais natural de realizar do que o Tap-dance, mas implementei mesmo assim para me familiarizar com a funcionalidade do QMK).

Breve explicação do meu layout, por camada:
![Captura de tela de 2022-11-01 22-40-05](https://user-images.githubusercontent.com/74465757/199374616-3666dca6-7115-495c-8b21-ebe314ce4d2d.png)
Camada principal e padrão. as teclas são dispostas semelhante ao ABNT, permitindo pontuação e ç normal ao usar o idioma de entrada PT-BR no sistema.
     


* Keyboard Maintainer: [QMK Community](https://github.com/qmk)
* Hardware Supported: Atmega32A
* Hardware Availability: [AliExpress](https://www.aliexpress.com/item/jj50-v1-0-Custom-Mechanical-Keyboard-50-PCB-programmed-50-preonic-layouts-bface-firmware-with-rgb/32848915277.html); [KPrepublic](https://kprepublic.com/collections/jj50-50/products/jj50-50-custom-keyboard-pcb-similar-with-preonic)

Make example for this keyboard (after setting up your build environment):

    make kprepublic/jj50:default

Flashing example for this keyboard ([after setting up the bootloadHID flashing environment](https://docs.qmk.fm/#/flashing_bootloadhid))

    make kprepublic/jj50:default:flash

**Reset Key**: Hold down the key `Backspace` (`Key below the top right key`) while plugging in the keyboard.

See the [build environment 
setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
