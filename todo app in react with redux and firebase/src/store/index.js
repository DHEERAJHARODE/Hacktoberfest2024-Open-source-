import { createStore, applyMiddleware, compose } from "redux";
import thunk from "redux-thunk";
import reducerFunction from "./Reducers";
const composeEnhancers = window.__REDUX_DEVTOOLS_EXTENSION_COMPOSE__ || compose;

const store = createStore(
    reducerFunction,
    // window.__REDUX_DEVTOOLS_EXTENSION__ && window.__REDUX_DEVTOOLS_EXTENSION__(),
    // composeEnhancers(applyMiddleware(thunk)));
    applyMiddleware(thunk));

export default store;