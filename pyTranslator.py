#!/usr/bin/env python3
# -*- coding: Latin 1 -*-

def getSupportedLanguages(s) :
    try:
        from deep_translator import GoogleTranslator

        langsList = GoogleTranslator.get_supported_languages()
        langsList = [lang.title() for lang in langsList]

        listToStr = ','.join(map(str, langsList))
        return listToStr
    except :
        return "ERROR"

def translateDeepTranslator_text(fileName="", srcLang="chinese (simplified)", destLang="english"): # I prefer to use this function because it is quite simple and fast
# -*- coding: Latin 1 -*-
    from deep_translator import GoogleTranslator
    import os
    import chardet

    try:
        if not(os.path.isfile(fileName)) :
            return "ERROR1"

        head, tail = os.path.split(fileName)
        outputFileName = head + "\\_" + tail
        tempFileName = head + "\\__" + tail

        charenc = 'utf-8'
        with open(fileName, mode='rb') as f:
            rawdata = f.read()
            result = chardet.detect(rawdata)
            charenc = result['encoding']
            del f
            del rawdata
            del result
        
        with open(fileName, mode='r', encoding=charenc, errors='ignore' ) as f :
            s = f.read()
            s = s.encode('utf8', 'ignore').decode('utf8')
            open(tempFileName, mode='w', encoding='utf8').write(s)
            del f
            del s

        translated = GoogleTranslator(source=srcLang.lower(), target=destLang.lower()).translate_file(tempFileName)

        os.remove(tempFileName)

        with open(outputFileName, 'w') as f:
            f.write( translated )
            del f

        del translated

        return "OK"
    except Exception:
        return "ERROR2"

