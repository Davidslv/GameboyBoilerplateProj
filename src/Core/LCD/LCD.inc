if      !def(CORE_LCD_INC)
CORE_LCD_INC  set  1

include "./src/Includes.inc"

; Other file was disabled, just too buggy both on it's on and
; largely because of RGBDS unavoidable persistent bugs

is_hblank:       macro
    ld a, [rSTAT]
	and STATF_MODE_MASK
    cp 0
endm

is_vblank:       macro
    ld a, [rLCDC]
    bit 7, a
    jr z, .end\@

    ld a, [rSTAT]
	and STATF_MODE_MASK
    cp 1

.end\@
endm

is_vram_busy: macro
    ld a, [rSTAT]
	and STATF_MODE_MASK
    cp 2
endm

is_oam_vram_busy: macro
    ld a, [rSTAT]
	and STATF_MODE_MASK
    cp 3
endm

wait_hblank:		macro
.wait\@
	is_hblank
	jr nz, .wait\@ ; Proceed when LCD reports HBlank
endm

wait_vblank:		macro
.wait\@
	is_vblank
	jr nz, .wait\@ ; Proceed when LCD reports VBlank
endm

; Why? Because it looks waaayy prettier lol
; Turns LCD on or off
; \1 "on" or "off"
lcd:         macro
    if \1 == "on"
        call EnableLCD
    else
        call DisableLCD
    endc    
endm

endc