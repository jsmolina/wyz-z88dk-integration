// zcc +zx main.c sham.mus.asm effects.asm -create-app
// zcc +zx -v -startup=31 -DWFRAMES=3 -clib=sdcc_iy main.c sham.mus.asm effects.asm -create-app
#include <sound/aywyz.h>
#include <im2.h>
#include <stdlib.h>
#include <string.h>
#include <intrinsic.h>
#include <z80.h>
#include <intrinsic.h>
#include <arch/zx.h>
#include <arch/zx/sp1.h>
#include <sound/aywyz.h>
#include <input.h>



extern wyz_song mysong;
extern wyz_effects myeffects;

IM2_DEFINE_ISR(playmusic)
{

   ay_wyz_play();

}


void setup_int() {
   im2_init((void *)0xd000); // CRT_ORG = 25124
   memset((void *)0xd000, 0xd1, 257);

   z80_bpoke(0xd1d1, 0xc3);
   z80_wpoke(0xd1d2, (unsigned int)playmusic);
}


void main()
{
   //printf("%cWYZ Tracker example\n",12);

   // Load the tracker file
   ay_wyz_init(NULL);
   // Setup the effects
   ay_wyz_effect_init(&myeffects);
   // Play song 1 within the  file
   //ay_wyz_start(0);

   // Setup interrupt
   setup_int();
   intrinsic_ei();

   // Just loop
   while  ( 1 ) {
      if(in_key_pressed(IN_KEY_SCANCODE_1)) {
        zx_border(INK_BLUE);
          ay_wyz_start_effect(3, 0);
      } else if(in_key_pressed(IN_KEY_SCANCODE_2)) {
        zx_border(INK_BLUE);
          ay_wyz_start_effect(3, 1);
      } else if(in_key_pressed(IN_KEY_SCANCODE_3)) {
        zx_border(INK_BLUE);
          ay_wyz_start_effect(4, 2);
      } else if(in_key_pressed(IN_KEY_SCANCODE_4)) {
        zx_border(INK_BLUE);
          ay_wyz_start_effect(4, 3);
      } else {
        zx_border(INK_BLACK);
      }
   }
}

