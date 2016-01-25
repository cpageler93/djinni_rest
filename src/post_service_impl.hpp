#pragma once

#include "posts_service.hpp"
#include "post_model.hpp"

namespace djinni_rest {

	class PostsServiceImpl : public PostsService {
	public:

		// Constructor
		PostsServiceImpl();

		// Methods
		std::vector<PostModel> get_posts_index();

	};

}
