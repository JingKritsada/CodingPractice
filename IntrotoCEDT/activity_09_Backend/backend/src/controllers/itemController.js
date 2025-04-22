import { itemFromObject } from "../models/itemModel.js";
import { items } from "../data/items.js";
import { Console } from "console";
//
/** @type {import("express").RequestHandler} */
export const createItem = async (req, res) => {
  try {
    const item = itemFromObject(req.body);
    items.push(item);
    res.status(200).json({ message: "OK" });
  } catch (e) {
    console.error(e);
    res.status(400).json({ error: "Bad Request" });
  }
};

let filtered = "ทั้งหมด";

/** @type {import("express").RequestHandler} */
export const getItems = async (req, res) => {
  if (filtered != "ทั้งหมด") {
    res.status(200).json(items.filter(item => item.name == filtered));
  } else if (filtered == "ทั้งหมด") {
    res.status(200).json(items);
  }
};

/** @type {import("express").RequestHandler} */
export const deleteItem = async (req, res) => {
  try {
    const id = req.params.id;
    const idx = items.findIndex(item => item._id === id)

    if (id === -1) {
      res.status(400).json({ message: "Not Found" });
    }

    items.splice(idx, 1);
    res.status(200).json({ message: "Item deleted successfully" });
  }
  catch (e) {
    console.error(e);
    res.status(400).json({ error: "Bad Request" });
  }

};

/** @type {import("express").RequestHandler} */
export const filterItems = async (req, res) => {
  try {
    filtered = req.body["name"];
    res.status(200).json({ message: "OK " + filtered });
  }
  catch (e) {
    console.error(e);
    res.status(400).json({ error: "Bad Request" });
  }
};