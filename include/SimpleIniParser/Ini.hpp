/*
 * SimpleIniParser
 * Copyright (c) 2020 Nichole Mattera
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above 
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#pragma once

#include <sstream>
#include <string>
#include <vector>

#include "IniSection.hpp"
#include "IniOption.hpp"

namespace simpleIniParser {
    class Ini {
        public:
            std::vector<IniOption *> options;
            std::vector<IniSection *> sections;
            std::string magic;

            ~Ini();
            std::string build();
            IniOption * findFirstOption(std::string term, bool caseSensitive = true, IniOptionType type = IniOptionType::Any, IniOptionSearchField field = IniOptionSearchField::Key);
            IniOption * findOrCreateFirstOption(std::string key, std::string val, bool caseSensitive = true, IniOptionType type = IniOptionType::Any, IniOptionSearchField field = IniOptionSearchField::Key);
            std::vector<IniOption *> findAllOptions(std::string term, bool caseSensitive = true, IniOptionType type = IniOptionType::Any, IniOptionSearchField field = IniOptionSearchField::Key);
            IniSection * findSection(std::string term, bool caseSensitive = true, IniSectionType type = IniSectionType::Any);
            IniSection * findOrCreateSection(std::string term, bool caseSensitive = true, IniSectionType type = IniSectionType::Any);
            std::vector<IniSection *> findAllSections(std::string term, bool caseSensitive = true, IniSectionType type = IniSectionType::Any);
            bool writeToFile(std::string path);
            static Ini * parseFile(std::string path);
            static Ini * parseFileWithMagic(std::string path, std::string magic);
            static Ini * parseOrCreateFile(std::string path, std::string magic="");
            void deleteSection(std::string term, bool caseSensitive = true, IniSectionType type = IniSectionType::Any);

        private:
            static Ini * _parseContent(std::stringstream * content, std::string magic);
        
    };
}
