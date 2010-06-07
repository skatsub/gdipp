#pragma once

#include "setting_cache.h"
#include "os2_metrics.h"
using namespace std;

class gdimm_text
{
public:
	struct gdimm_text_context
	{
		HDC hdc;
		OUTLINETEXTMETRICW *outline_metrics;
		const wchar_t *font_face;
		const font_setting_cache *setting_cache;

		bool init(HDC hdc);

	private:
		vector<BYTE> _metric_buf;
	};

protected:
	const gdimm_text_context *_context;
	LOGFONTW _font_attr;
	UINT _text_alignment;
	BITMAPINFOHEADER _dc_bmp_header;
	COLORREF _text_color;

public:
	virtual ~gdimm_text();

	virtual bool begin(const gdimm_text_context *context);
	virtual bool text_out(int x, int y, UINT options, CONST RECT *lprect, LPCWSTR lpString, UINT c, CONST INT *lpDx) = 0;
	virtual void end();
};