
	SECTION	rodata_user

	PUBLIC	_myeffects

	defc	_myeffects = EFFECT_TABLE


;SFX format is quite simple:
;
;defb byte1,byte2
;defb byte1,byte2
;...
;defb $ff

;Where byte 1 and bits 7, 6, 5 & 4 from byte2 are the sound frequency 
;and bits 3, 2, 1 & 0 of byte2 is the amplitude.
;Effect finishes when &ff is found.
; NOTE: you cannot mix non-noise channel effects with noise channel effects

EFFECT_TABLE:
                defw _EFECTO0
                defw _EFECTO1
                defw _EFECTO2



_EFECTO0:
EFECTO0:	DB $00, $3E, $00
			DB $00, $59, $00
			DB $FF
_EFECTO1:
DB $D1, $2E, $00
			DB $2E, $3B, $01
			DB $00, $57, $07
			DB $FF

_EFECTO2:
DB $00, $0A, $13
			DB $FF
