import Item from "../models/itemModel.js";

export const createItem = async (req, res) => {
  try {
    const newItem = new Item(req.body);
    await newItem.save();

    res.status(200).json({ message: "OK" });
  } catch (err) {
    if (err.name === "ValidationError") {
      res.status(400).json({ error: "Bad Request" });
    } else {
      res.status(500).json({ error: "Internal server error." });
    }
  }
};

export const getItems = async (req, res) => {
  const items = await Item.find();

  res.status(200).json(items);
};

export const deleteItem = async (req, res) => {
  // TODO 2: Implement deleteItem function -----------------------------------
  try {
    const id = req.params.id;
    const deleted = await Item.findByIdAndDelete(id);
    res.status(200).json({ message: "Item deleted successfully" });
  }
  catch (e) {
    console.error(e);
    res.status(400).json({ error: "Bad Request" });
  }
  // ------------------------------------------------------------------------
};

export const filterItems = async (req, res) => {
  // TODO 3: Implement filterItems function ---------------------------------
  try {
    const name = req.body['name']
    const lower = req.body['lowerPrice']
    const upper = req.body['upperPrice']

    let config = { price: { $gte: lower, $lte: upper } }

    if (name != 'ทั้งหมด') {
      config['name'] = name
    }

    const result = await Item.find(config)
    res.status(200).json(result)
  } catch (e) {
    res.status(500).json({ error: 'Internal server error.' })
  }
  // ------------------------------------------------------------------------
};