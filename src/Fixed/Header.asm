section "Header", rom0 [$104]
	; The header is generated by rgbfix both for ease and to help circumvent trademark and copyright infringement
	; The space here is allocated to prevent code from being overwritten.
	ds $150 - $104
