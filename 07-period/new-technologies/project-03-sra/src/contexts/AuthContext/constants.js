import { getNextId } from "@/utils/getNextId";
import AsyncStorage from "@react-native-async-storage/async-storage";

export const USER_REQUIRED_FIELDS = ["name", "email", "password"];

export const isUserPayloadValid = (payload) => {
  const payloadKeys = Object.keys(payload);
  const isValid = USER_REQUIRED_FIELDS.every((field) =>
    payloadKeys.includes(field)
  );
  return isValid;
};

export const loadUsersFromLocalStorage = async () => {
  try {
    const users = await AsyncStorage.getItem("users");
    return users ? JSON.parse(users) : [];
  } catch {
    return [];
  }
};

export const saveUsersToLocalStorage = async (users) => {
  try {
    await AsyncStorage.setItem("users", JSON.stringify(users));
  } catch {
    console.error("Failed to save users to local storage");
  }
};

export const USERS_ACTIONS = {
  create: (state, payload) => {
    if (!isUserPayloadValid(payload)) {
      return state;
    }

    const newUser = {
      ...payload,
      id: String(getNextId(state)),
    };

    return [...state, newUser];
  },
  delete: (state, payload) => {
    return state.filter((user) => user.id !== payload.id);
  },
  update: (state, payload) => {
    if (!isUserPayloadValid(payload)) {
      return state;
    }

    return state.map((user) =>
      user.id === payload.id
        ? { ...user, ...payload, id: String(user.id) }
        : user
    );
  },
  loadEvents: (_, payload) => payload,
};

export const usersReducer = (state, action) => {
  const { payload, type } = action;
  const userAction = USERS_ACTIONS[type];
  const newState = userAction ? userAction(state, payload) : state;

  saveUsersToLocalStorage(newState);
  return newState;
};
