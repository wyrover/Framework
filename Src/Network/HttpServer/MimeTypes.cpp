//
// mime_types.cpp
// ~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2012 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "MimeTypes.hpp"

namespace Framework {
	namespace Network {
		namespace MimeTypes {

			struct mapping
			{
				const char* extension;
				const char* mime_type;
			} mappings[] =
			{
				{ "gif", "image/gif" },
				{ "htm", "text/html" },
				{ "html", "text/html" },
				{ "jpg", "image/jpeg" },
				{ "png", "image/png" },
				{ 0, 0 } // Marks end of list.
			};

			std::string extension_to_type(const std::string& extension)
			{
				for (mapping* m = mappings; m->extension; ++m)
				{
					if (m->extension == extension)
					{
						return m->mime_type;
					}
				}

				return "text/html";
			}

		} // namespace mime_types
	} 
} 