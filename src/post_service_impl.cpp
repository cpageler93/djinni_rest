#include "post_service_impl.hpp"
#include <string>

namespace djinni_rest {
	
	std::shared_ptr<PostsService> PostsService::create() {
		return std::make_shared<PostsServiceImpl>();
	}

    PostsServiceImpl::PostsServiceImpl() {

    }

    std::vector<PostModel> PostsServiceImpl::get_posts_index() {
		auto v = std::vector<PostModel>();
		
		// call http://jsonplaceholder.typicode.com/

		auto post = PostModel(0, "title", "body");
		v.push_back(post);
		
        return v;
    }


}