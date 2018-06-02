include "./src/Includes.inc"

section "DMA", rom0
DMAInstall::
	; Copy DMA Routine to HRAM
	copy RawDMACopyFunc, hDMACopyFunc, RawDMACopyFuncEnd-RawDMACopyFunc
	ret

RawDMACopyFunc:
	; first we load the OAM page into the DMA register at $FF46
	ld 		a, [wOamPage]
	ld      [rDMA], a

	; DMA transfer begins, we need to wait 160 microseconds while it transfers
	; the following loop takes exactly that long
	ld      a, $28
.loop:
	dec     a
	jr      nz, .loop
	ret
RawDMACopyFuncEnd:
